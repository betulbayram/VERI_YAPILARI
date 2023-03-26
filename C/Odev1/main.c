#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct node {
    int data;
    int prev;
    int next;
};

struct node arr[MAX_SIZE];
int head = -1;
int tail = -1;
int free_list = 0;

void init_list() {
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        arr[i].next = i + 1;
    }
    arr[MAX_SIZE - 1].next = -1;
}

int get_node() {
    int new_node = free_list;
    if (new_node == -1) {
        printf("No free nodes.\n");
        exit(1);
    }
    free_list = arr[new_node].next;
    arr[new_node].prev = -1;
    arr[new_node].next = -1;
    return new_node;
}

void free_node(int node) {
    arr[node].next = free_list;
    free_list = node;
}

void insert_node(int value) {
    int new_node = get_node();
    arr[new_node].data = value;
    if (head == -1) {
        head = new_node;
        tail = new_node;
    }
    else {
        arr[new_node].prev = tail;
        arr[tail].next = new_node;
        tail = new_node;
    }
}

void delete_node(int value) {
    int current = head;
    while (current != -1) {
        if (arr[current].data == value) {
            if (current == head) {
                head = arr[current].next;
                if (head != -1) {
                    arr[head].prev = -1;
                }
            }
            else if (current == tail) {
                tail = arr[current].prev;
                if (tail != -1) {
                    arr[tail].next = -1;
                }
            }
            else {
                arr[arr[current].prev].next = arr[current].next;
                arr[arr[current].next].prev = arr[current].prev;
            }
            free_node(current);
            return;
        }
        current = arr[current].next;
    }
}

void print_list() {
    int current = head;
    while (current != -1) {
        printf("%d ", arr[current].data);
        current = arr[current].next;
    }
    printf("\n");
}

int main() {
    init_list();

    int choice, value;
    while (1) {
        printf("1. Insert node\n");
        printf("2. Delete node\n");
        printf("3. Print list\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insert_node(value);
                break;
            case 2:
                printf("Enter the value to delete: ");
                scanf("%d", &value);
                delete_node(value);
                break;
            case 3:
                print_list();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
