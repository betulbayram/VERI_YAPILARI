#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Listenin orta elemanını bulur
struct Node* getMiddleNode(struct Node* head, struct Node* tail) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// İkili arama algoritması ile elemanı bulur
struct Node* binarySearch(struct Node* head, struct Node* tail, int x) {
    while (head != tail) {
        struct Node* middle = getMiddleNode(head, tail);
        if (middle->data == x) {
            return middle;
        } else if (middle->data < x) {
            head = middle->next;
        } else {
            tail = middle->prev;
        }
    }

    if (head->data == x) {
        return head;
    } else {
        return NULL;
    }
}

// İki yönlü bağlı listeyi oluşturur
struct Node* createList(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = arr[0];
    head->prev = NULL;
    head->next = NULL;

    struct Node* tail = head;

    for (int i = 1; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->prev = tail;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

int main() {
    int arr[] = {2, 3, 5, 7, 11, 13, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Node* head = createList(arr, n);

    int x;
    printf("Aranan eleman: ");
    scanf("%d", &x);

    struct Node* result = binarySearch(head, NULL, x);

    if (result == NULL) {
        printf("Eleman bulunamadi\n");
    } else {
        printf("Eleman bulundu: %d\n", result->data);
    }

    return 0;
}
