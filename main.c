#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int     fd;
    int     write_fd;
    char    *line;

    (void)argc;
    (void)argv;

    write_fd = open("po.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (write_fd < 0)
        return (1);
    write(write_fd, "hello\nhow\nare\nyou", 17);
    close(write_fd);
    fd = open("po.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
