get next line use read, read is dumb cz it reads only based on chunk of memory which is the buffer so we need a
stash_container to hold in it the lines which ginna be a static variable.
why static variable cz it the only var that can hold his
value inside it till the programme terminated.

Our GNL workflow is essentially:
1. Check whether stash already contains \n.
2. If not, call read() and append the new chunk.
3. Repeat until we find \n or reach EOF.
4. Extract the first line.
5. Keep the remaining data in stash for the next call.

We can divide GNL into three logical operations:
1. Reading: Collect chunks from the file descriptor.
2. Extracting: Get the first line from the stash.
3. Updating: Remove the extracted line from the stash while keeping the remaining bytes.

