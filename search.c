#include "header.h"
#include <ctype.h>
#include "header.h"
#include <ctype.h>
#include <string.h>

int search_database(main_node *head[], char *word)
{
    // remove newline
    word[strcspn(word, "\n")] = '\0';

    // convert to lowercase
    for(int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }

    int index = word[0] - 'a';

    if(index < 0 || index > 25)
    {
        printf("Invalid word\n");
        return FAILURE;
    }

    main_node *temp = head[index];

    while (temp)
    {
        if (strcmp(temp->word, word) == 0)
        {
            sub_node *sub = temp->sub_link;
            while (sub)
            {
                printf("%s : %d\n", sub->file_name, sub->file_count);
                sub = sub->sub_link;
            }
            return SUCCESS;
        }
        temp = temp->main_link;
    }

    printf("Word not found\n");
    return FAILURE;
}