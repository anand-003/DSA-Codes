#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("%d inserted\n", value);
}

void deleteFromBeginning() {
    if (head == NULL) {
        printf("Linked List is empty\n");
    } else {
        struct Node* temp = head;
        printf("%d deleted\n", head->data);
        head = head->next;
        free(temp);
    }
}

void display() {
    if (head == NULL) {
        printf("Linked List is empty\n");
    } else {
        struct Node* temp = head;

        printf("Linked List elements are:\n");

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main() {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);

    display();

    deleteFromBeginning();

    display();

    return 0;
}