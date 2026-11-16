

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    
    FILE *pF = fopen("test.txt", "r");
    char buffer[255];
    fgets(buffer, 255, pF);
    printf("%s", buffer);

    fclose(pF);
    return 0;
}
