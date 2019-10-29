//
// Created by rossetta on 2019/8/27.
//

#include <malloc.h>
#include <stdio.h>
#include "list.h"

/* given a key, create head node of a singly linked list. */
N *create_head(int key) {
    N *head = (N *) malloc(NODE_SIZE);
    if (head) {
        head->key = key;
        /* make sure head->next points to NULL. */
        head->next = NULL;
        return head;
    } else return NULL;
}

/* given a key, append a new node at the end of a singly linked list. */
void append_node(N *head, int key) {
    /* appending to an empty list is illegal. */
    if (!head)
        return;

    /* make a copy of list head. */
    N *tmp = head;

    /* find last node of the list. */
    while (head->next)
        head = head->next;

    /* now head points to the last node of the list. */
    N *new_node = (N *) malloc(NODE_SIZE);
    if (new_node) {
        head->next = new_node;
        new_node->key = key;
        new_node->next = NULL;
    } else {
        printf("Append %d failed! Reason: cannot allocate space.\n", key);
        return;
    }
}

void insert_node(N **head_ref, int index, int key) {
    /* inserting into an empty list is illegal. */
    if (!(*head_ref))
        return;

    /* make space for inserted key. */
    N *new_node = (N *) malloc(NODE_SIZE);
    if (!new_node)
        return;
    new_node->key = key;

    /* if index is located at list head,
     * the head pointer needs to point to the inserted node. */
    if (index == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    } else if (index < 0)
        return;

    /* find the node previous to the node to be inserted. */
    N *prev = *head_ref;
    for (int i = 0; prev != NULL && i < index - 1; i++)
        prev = prev->next;

    /* if the index is beyond the list size. */
    if (prev == NULL || prev->next == NULL)
        return;

    /* now prev points 1 position before the insertion. */
    new_node->next = prev->next;
    prev->next = new_node;
}

void delete_node_key(N **head_ref, int key) {
    N *tmp = *head_ref;

    /* if the node to be deleted is head of the list,
     * the head pointer needs to point at the next node. */
    if ((tmp != NULL) && (tmp->key == key)) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    /* find the node previous to the node to be deleted. */
    N *prev = NULL;
    while ((tmp != NULL) && (tmp->key != key)) {
        prev = tmp;
        tmp = tmp->next;
    }

    /* if the key cannot be found. */
    if (!tmp)
        return;

    if (prev) {
        prev->next = tmp->next;
        free(tmp);
    }
}

void delete_node_index(N **head_ref, int index) {
    N *tmp = *head_ref;

    /* if the node to be deleted is the head of the list. */
    if (tmp != NULL && index == 0) {
        *head_ref = tmp->next;
        free(tmp);
        return;
    }

    if (index < 0) return;

    /* find the node previous to the node to be deleted. */
    N *prev = NULL;
    for (int i = 0; tmp != NULL && i < index; i++) {
        prev = tmp;
        tmp = tmp->next;
    }

    /* if the index is out of range. */
    if (!tmp) return;

    if (prev) {
        prev->next = tmp->next;
        free(tmp);
    }
}

int index_node_key(N *head, int key) {
    int result = -1;
    while (head) {
        result++;
        if (head->key == key)
            return result;
        head = head->next;
    }
    return -1;
}

int query_node_key(N *head, int index) {
    if (!head) {
        printf("list is empty!\n");
        return -1;
    }
    if (index < 0) {
        printf("index [%d] out of range!\n", index);
        return -2;
    }
    if (index == 0)
        return head->key;

    N *tmp = head;

    for (int i = 0; tmp != NULL && i < index; i++)
        tmp = tmp->next;
    if (!tmp) {
        printf("index [%d] out of range!\n", index);
        return -2;
    }

    return tmp->key;
}

int count_node(N *head) {
    int result = 0;
    if (!head) return result;

    while (head) {
        head = head->next;
        result++;
    }

    return result;
}

void show_list(N *head) {
    if (head) {
        while (head) {
            if (head->next)
                printf("%d,", head->key);
            else
                printf("%d\n", head->key);
            head = head->next;
        }
    } else printf("empty list!\n");
}

void reverse_list(N **head_ref) {
    N *current = *head_ref;
    N *prev = NULL;
    N *next = NULL;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head_ref = prev;
}

void destroy_list(N **head_ref) {
    /* cannot destroy an empty list. */
    N *current = *head_ref;
    N *next = NULL;

    if (!current) return;

    /* free space of the list. */
    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}
