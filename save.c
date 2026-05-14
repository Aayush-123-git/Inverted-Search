#include "header.h"
#include <ctype.h>

int save_database(main_node *head[], char *filename)
{
    FILE *fp = fopen(filename, "w");
    if (!fp) return FAILURE;

    for (int i = 0; i < 27; i++)
    {
        main_node *temp = head[i];

        while (temp)
        {
            fprintf(fp, "%s ", temp->word);

            sub_node *sub = temp->sub_link;
            while (sub)
            {
                fprintf(fp, "%s:%d ", sub->file_name, sub->file_count);
                sub = sub->sub_link;
            }
            fprintf(fp, "\n");
            temp = temp->main_link;
        }
    }

    fclose(fp);
    return SUCCESS;
}