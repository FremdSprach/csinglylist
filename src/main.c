#include <stdio.h>

#include "list.h"

int main() {
    N *head = create_head(0);

    append_node(head, 1);
    show_list(head);

    append_node(head, 2);
    show_list(head);

    reverse_list(&head);
    show_list(head);

    return 0;
}
