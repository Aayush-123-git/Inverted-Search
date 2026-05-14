#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

// SUB NODE
typedef struct sub_node
{
    int file_count;
    char file_name[50];
    struct sub_node *sub_link;
} sub_node;

// MAIN NODE
typedef struct main_node
{
    int word_count;
    char word[50];
    struct main_node *main_link;
    sub_node *sub_link;
} main_node;

// PROTOTYPES
int validate(int argc, char *argv[]);
int create_database(main_node *head[], char *argv[]);
sub_node *create_subnode(sub_node **sub_head, char *filename);
int search_database(main_node *head[], char *word);
int save_database(main_node *head[], char *filename);
int update_database(main_node *head[], char *filename);

#endif