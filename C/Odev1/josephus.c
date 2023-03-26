#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = new_node;
    return new_node;
}

void insert_node(struct node **head_ref, int value) {
    struct node *new_node = create_node(value);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    }
    else {
        struct node *last = *head_ref;
        while (last->next != *head_ref) {
            last = last->next;
        }
        new_node->next = *head_ref;
        last->next = new_node;
    }
}

void delete_node(struct node **head_ref, struct node *prev_node) {
    struct node *current = prev_node->next;
    if (*head_ref == current) {
        *head_ref = current->next;
    }
    prev_node->next = current->next;
    free(current);
}

void josephus(struct node **head_ref, int k) {
    struct node *current = *head_ref;
    while (current->next != current) {
        for (int i = 1; i < k; i++) {
            current = current->next;
        }
        delete_node(head_ref, current);
    }
    *head_ref = current;
}

void print_list(struct node *head) {
    struct node *current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int n, k;
    printf("Enter the number of people: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    for (int i = 1; i <= n; i++) {
        insert_node(&head, i);
    }

    josephus(&head, k);

    printf("The last person standing is: %d\n", head->data);

    return 0;
}
