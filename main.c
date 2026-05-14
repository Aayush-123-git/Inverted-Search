#include "header.h"
#include <ctype.h>
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./inverted_search file1.txt file2.txt\n");
        return 1;
    }

    if (validate(argc, argv) == FAILURE)
    {
        printf("Validation failed\n");
        return 1;
    }

    main_node *head[27] = {NULL};

    int choice;
    char filename[50];
    char word[50];

    int create_flag = 0;
    int update_flag = 0;

    while (1)
    {
        printf("\n1.Create\n2.Search\n3.Save\n4.Update\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (create_flag)
                printf("Database already created\n");
            else
            {
                create_database(head, argv);
                create_flag = 1;
                update_flag = 0;
                printf("Database created\n");
            }
            break;

        case 2:
            printf("Enter word: ");
            scanf("%s", word);
            search_database(head, word);
            break;

        case 3:
            printf("Enter file name: ");
            scanf("%s", filename);
            save_database(head, filename);
            break;

        case 4:
            if (update_flag)
                printf("Already updated\n");
            else
            {
                printf("Enter file name: ");
                scanf("%s", filename);
                update_database(head, filename);
                update_flag = 1;
                create_flag = 0;
                printf("Updated successfully\n");
            }
            break;

        case 5:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }
}