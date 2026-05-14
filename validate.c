#include "header.h"
#include <ctype.h>

int validate(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        FILE *fp = fopen(argv[i], "r");
        if (!fp)
        {
            printf("File %s not found\n", argv[i]);
            return FAILURE        ;
        }
        fclose(fp);
    }
    return SUCCESS;
}