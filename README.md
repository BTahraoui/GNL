*This project has been created as part of the 42 curriculum by batahrao.*

# get_next_line

## Description

`get_next_line` is a 42 project that implements a function which reads one
text line at a time from a file descriptor. The function returns the line,
including its terminating newline character when one is present, and returns
`NULL` when the end of the file is reached or an error occurs.

The project introduces efficient reading with a fixed `BUFFER_SIZE`, handling
of partial reads, preservation of data left after a newline, and memory
management. It is designed to work for regular files, and it can also be used
with standard input or other readable file descriptors.

This repository contains the following files:

- `get_next_line.h`: public API and project-wide declarations.
- `get_next_line.c`: the line-reading and helper functions.
- `get_next_line_utils.c`: string length, search, copy, join, and duplicate
  helpers.

The default `BUFFER_SIZE` is `1337`, and it can be overridden at compilation
time with `-D BUFFER_SIZE=<value>`.

## Instructions

### Compilation

There is no standalone build system in this repository. Compile the source files
as part of a program or archive the objects:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	-c get_next_line.c get_next_line_utils.c

ar rcs libget_next_line.a get_next_line.o get_next_line_utils.o
```

The mandatory API is declared in `get_next_line.h`:

```c
char *get_next_line(int fd);
```

### Usage

Include the header and repeatedly call `get_next_line` until it returns `NULL`.
Callers are responsible for freeing each returned line.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int     fd = open("example.txt", O_RDONLY);
	char    *line;

	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
```

Compile an example together with the project sources:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
	main.c get_next_line.c get_next_line_utils.c -o example
./example
```

> The repository's current `get_next_line.c` also contains a temporary `main`
> demonstration, and the `get_next_line` function body is not yet finished.
> Remove or replace that `main` and complete `get_next_line` before linking
> multiple test programs.

## Algorithm and implementation

The selected algorithm is a **static stash plus chunked reading** approach.
Each call reads only enough data to produce a complete line:

1. **Preserve unread data:** A static stash remains between calls and holds all
   bytes that were read after the previous newline.
2. **Read in chunks:** `read_to_stash` requests at most `BUFFER_SIZE` bytes and
   appends each chunk to the stash.
3. **Stop at the next newline:** Reading continues only while the stash has no
   newline and `read` has not reached the end of the file.
4. **Extract the line:** `cut_line` copies from the stash beginning through the
   newline, or through the end of the stash at EOF.
5. **Update the stash:** `get_rest` removes the returned line and keeps the
   remaining bytes for the next call.
6. **Release memory:** `ft_join_free` joins a read buffer to the stash and frees
   the old stash, preventing stale buffers from accumulating.

This approach is preferable to reading from the file descriptor one character
at a time because `read` is called in bounded chunks, but it remains independent
of the entire file size. It is preferable to loading the whole file because
memory usage is limited mainly to the current line and stash; the result must
still fit in memory because `get_next_line` returns a complete allocated line.
The static stash is necessary to preserve bytes already read beyond the newline,
while helper functions keep newline detection and memory allocation explicit.

Edge behavior must include returning the final line without a newline at EOF,
returning `NULL` for an invalid descriptor or read failure, and returning `NULL`
after all lines have been consumed. Memory returned by the function must be
freed by the caller.

## Resources

- [GNU C Library: I/O overview](https://www.gnu.org/software/libc/manual/html_node/I_002fO-Overview.html)
- [POSIX `read` documentation](https://pubs.opengroup.org/onlinepubs/9699919799/functions/read.html)
- [Linux `read(2)` manual](https://man7.org/linux/man-pages/man2/read.2.html)
- [42 get_next_line project specification](https://github.com/42School/get_next_line)
- [Open Group file descriptor overview](https://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html)

### AI usage

AI assistance was used to inspect the existing C sources, draft this README,
and explain the intended buffered-reading algorithm. AI was not used to
generate the runtime implementation. The actual project logic and source files
should be reviewed, tested, and corrected where required.
