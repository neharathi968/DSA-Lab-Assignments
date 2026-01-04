#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Insert at end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Insert at specific position
void insertAtPosition(int value, int pos) {
    struct Node* newNode = createNode(value);
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp->next != head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Traverse forward
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Count nodes
int countNodes() {
    if (head == NULL) return 0;
    int count = 0;
    struct Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Search element
void search(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    int pos = 1;
    do {
        if (temp->data == value) {
            printf("Element %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found in the list.\n", value);
}

// Delete at beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    struct Node* del = head;
    temp->next = head->next;
    head = head->next;
    free(del);
}

// Delete at end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    struct Node* del = temp->next;
    temp->next = head;
    free(del);
}

// Delete specific element
void deleteElement(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (head->data == value) {
        deleteAtBeginning();
        return;
    }
    struct Node* temp = head;
    while (temp->next != head && temp->next->data != value) {
        temp = temp->next;
    }
    if (temp->next->data == value) {
        struct Node* del = temp->next;
        temp->next = del->next;
        free(del);
    } else {
        printf("Element not found.\n");
    }
}

// Traverse in reverse (helper recursive)
void reverseTraverseHelper(struct Node* current, struct Node* start) {
    if (current->next != start) {
        reverseTraverseHelper(current->next, start);
    }
    printf("%d ", current->data);
}

void reverseTraverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Reverse List: ");
    reverseTraverseHelper(head, head);
    printf("\n");
}

// Menu
int main() {
    int choice, value, pos;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Traverse\n");
        printf("5. Delete at Beginning\n");
        printf("6. Delete at End\n");
        printf("7. Delete Specific Element\n");
        printf("8. Count Nodes\n");
        printf("9. Search Element\n");
        printf("10. Traverse in Reverse\n");
        printf("11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &pos);
                insertAtPosition(value, pos);
                break;
            case 4:
                traverse();
                break;
            case 5:
                deleteAtBeginning();
                break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteElement(value);
                break;
            case 8:
                printf("Number of nodes = %d\n", countNodes());
                break;
            case 9:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 10:
                reverseTraverse();
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
