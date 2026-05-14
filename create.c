#include "header.h"
#include <ctype.h>
sub_node *create_subnode(sub_node **sub_head, char *filename)
{
    sub_node *temp = *sub_head;

    while (temp)
    {
        if (strcmp(temp->file_name, filename) == 0)
        {
            temp->file_count++;
            return *sub_head;
        }
        temp = temp->sub_link;
    }

    sub_node *new = malloc(sizeof(sub_node));
    strcpy(new->file_name, filename);
    new->file_count = 1;
    new->sub_link = *sub_head;
    *sub_head = new;

    return *sub_head;
}

#include "header.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int create_database(main_node *head[], char *argv[])
{
    int i = 1;

    while(argv[i] != NULL)
    {
        FILE *fp = fopen(argv[i], "r");

        if(fp == NULL)
        {
            printf("File %s not found\n", argv[i]);
            i++;
            continue;
        }

        char word[100];

        while(fscanf(fp, "%s", word) != EOF)
        {
            // lowercase
            for(int j = 0; word[j]; j++)
                word[j] = tolower(word[j]);

            // remove punctuation
            int len = strlen(word);
            if(ispunct(word[len - 1]))
                word[len - 1] = '\0';

            int index = word[0] - 'a';
            if(index < 0 || index > 25)
                continue;

            main_node *temp = head[index], *prev = NULL;

            while(temp)
            {
                if(strcmp(temp->word, word) == 0)
                    break;
                prev = temp;
                temp = temp->main_link;
            }

            if(temp)
            {
                sub_node *sub = temp->sub_link, *sub_prev = NULL;

                while(sub)
                {
                    if(strcmp(sub->file_name, argv[i]) == 0)
                    {
                        sub->file_count++;
                        break;
                    }
                    sub_prev = sub;
                    sub = sub->sub_link;
                }

                if(!sub)
                {
                    sub_node *new_sub = malloc(sizeof(sub_node));
                    strcpy(new_sub->file_name, argv[i]);
                    new_sub->file_count = 1;
                    new_sub->sub_link = NULL;
                    sub_prev->sub_link = new_sub;
                }
            }
            else
            {
                main_node *new_main = malloc(sizeof(main_node));
                strcpy(new_main->word, word);
                new_main->main_link = NULL;

                sub_node *new_sub = malloc(sizeof(sub_node));
                strcpy(new_sub->file_name, argv[i]);
                new_sub->file_count = 1;
                new_sub->sub_link = NULL;

                new_main->sub_link = new_sub;

                if(prev == NULL)
                    head[index] = new_main;
                else
                    prev->main_link = new_main;
            }
        }

        fclose(fp);
        i++;
    }

    return SUCCESS;
}