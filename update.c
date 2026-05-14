#include "header.h"
#include <ctype.h>
int update_database(main_node *head[], char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (!fp) return FAILURE;

    char word[50], file[50];
    int count;

    while (fscanf(fp, "%s", word) != EOF)
    {
        int index = tolower(word[0]) % 97;

        main_node *new_main = malloc(sizeof(main_node));
        strcpy(new_main->word, word);
        new_main->word_count = 0;
        new_main->sub_link = NULL;
        new_main->main_link = head[index];
        head[index] = new_main;

        while (fscanf(fp, "%[^:]:%d ", file, &count) == 2)
        {
            sub_node *new_sub = malloc(sizeof(sub_node));

strcpy(new_sub->file_name, filename);
new_sub->file_count = count;

new_sub->sub_link = new_main->sub_link;
new_main->sub_link = new_sub;
        }
    }

    fclose(fp);
    return SUCCESS;
}