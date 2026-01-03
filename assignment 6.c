#include <stdio.h>

#define MAX 20

int info[MAX], next[MAX];
int start = -1;
int avail = 0;

// initialize available list
void init() {
    for (int i = 0; i < MAX - 1; i++)
        next[i] = i + 1;
    next[MAX - 1] = -1;
}

// allocate a node from available list
int getNode() {
    if (avail == -1) return -1;
    int p = avail;
    avail = next[p];
    return p;
}

// free node back to available list
void freeNode(int p) {
    next[p] = avail;
    avail = p;
}

// insert at beginning
void insertBeg(int x) {
    int p = getNode();
    if (p == -1) {
        printf("List is full!\n");
        return;
    }
    info[p] = x;
    next[p] = start;
    start = p;
}

// delete first element
void deleteBeg() {
    if (start == -1) {
        printf("List is empty!\n");
        return;
    }
    int p = start;
    start = next[p];
    freeNode(p);
}

// traverse list
void traverse() {
    if (start == -1) {
        printf("List is empty!\n");
        return;
    }
    int p = start;
    printf("List: ");
    while (p != -1) {
        printf("%d ", info[p]);
        p = next[p];
    }
    printf("\n");
}

int main() {
    int ch, x;
    init();

    while (1) {
        printf("\n1. Insert at beginning\n2. Traverse\n3. Delete first\n4. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &x);
                insertBeg(x);
                break;

            case 2:
                traverse();
                break;

            case 3:
                deleteBeg();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}
