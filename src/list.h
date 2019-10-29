//
// Created by rossetta on 2019/8/27.
//

#ifndef SINGLY_LINKED_LIST_LIST_H
#define SINGLY_LINKED_LIST_LIST_H

/* the structure of a singly linked list. */
struct Node {
    int key;
    struct Node *next;
};

typedef struct Node N;

static int NODE_SIZE = sizeof(N);

N *create_head(int key);

void append_node(N *head, int key);

void insert_node(N **head_ref, int index, int key);

void delete_node_key(N **head_ref, int key);

void delete_node_index(N **head_ref, int index);

int index_node_key(N *head, int key);

int query_node_key(N *head, int index);

int count_node(N *head);

void show_list(N *head);

void reverse_list(N **head_ref);

void destroy_list(N **head_ref);

#endif //SINGLY_LINKED_LIST_LIST_H
