*to do List, by batahrao*

Phase 0: Setup (15 min)
[ ] Create a folder with the 3 files (.c, _utils.c, .h)
[ ] Create main.c for testing (it will not be submitted)
[ ] Create a test.txt with 3 short lines
[ ] Write the 42 header guard in your .h
Phase 1: Understand the tools (30 min, ONLY these)
[ ] Read man 2 read. You only need to know: it returns how many bytes it read, 0 means end of file, -1 means error
[ ] Write a tiny program: open your test file, read 5 bytes into a buffer, print it. Change 5 to 1, then to 100. Watch what changes.
[ ] Read about static variables: a variable that keeps its value between function calls. Test with a small function that counts how many times it was called.

⚠️ Stop here for learning. You now know enough to start.

Phase 2: Write the helper functions (1 to 2 hours)

You probably need these (some are from your libft):

[ ] ft_strlen
[ ] ft_strchr: to find the \n
[ ] ft_strjoin: to glue the leftover + the new chunk
[ ] ft_substr (or similar): to cut the line out
[ ] Test each one alone in main.c before moving on
Phase 3: Plan on paper (20 min, no code)

Write this in plain words, in your own language:

[ ] “I keep a leftover string in a static variable.”
[ ] “Loop: while the leftover has no \n, read a chunk and add it to the leftover.”
[ ] “When there’s a \n (or end of file), cut the leftover in two: the line to return, and the new leftover.”
[ ] “If nothing is left and nothing was read, return NULL.”
Phase 4: Break it into 3 small functions

Build and test one at a time:

[ ] Function A: read and join until the leftover contains \n or the file ends
[ ] Function B: extract the line from the leftover
[ ] Function C: keep only what’s after the line (the new leftover), and free the old one
[ ] Connect them inside get_next_line
Phase 5: Test (this is where the bugs are)
[ ] Compile with -D BUFFER_SIZE=1, then 42, then 9999
[ ] Empty file
[ ] File with no \n at the end
[ ] File with only \n\n\n
[ ] A very long single line
[ ] Invalid fd (-1) → must return NULL
[ ] Call it in a loop until NULL, free each line
Phase 6: Clean up
[ ] Check leaks with valgrind --leak-check=full
[ ] Check every malloc is protected and every free happens
[ ] Run norminette
[ ] Max 25 lines per function, 5 functions per file
[ ] Remove your main.c before submitting
Phase 7: Bonus (only after everything above passes)
[ ] Handle multiple fds at once (reading file A, then B, then A again) with one static variable. Hint: think about an array indexed by fd.
[ ] Files named _bonus.c, _bonus.h