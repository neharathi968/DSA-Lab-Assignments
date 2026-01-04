#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Stack {
    int arr[MAX];
    int top;
};

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isStackEmpty(struct Stack *s) {
    return s->top == -1;
}

int isStackFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isQueueEmpty(struct Queue *q) {
    return q->front == -1;
}

int isQueueFull(struct Queue *q) {
    return q->rear == MAX - 1;
}

void pushStack(struct Stack *s, int value) {
    if (isStackFull(s)) {
        printf("stack full\n");
        return;
    }
    s->arr[++s->top] = value;
}

int popStack(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("stack empty\n");
        return -1;
    }
    int value = s->arr[s->top--];
    return value;
}

void traverseStack(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("stack empty\n");
        return;
    }
    printf("stack: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

void enqueue(struct Queue *q, int value) {
    if (isQueueFull(q)) {
        printf("queue full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->arr[++q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

void traverseQueue(struct Queue *q) {
    if (isQueueEmpty(q)) {
        printf("queue empty\n");
        return;
    }
    printf("queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void stackMenu() {
    struct Stack s;
    initStack(&s);
    int choice, value;
    
    do {
        printf("\nstack menu\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. traverse\n");
        printf("4. exit\n");
        printf("choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("value: ");
                scanf("%d", &value);
                pushStack(&s, value);
                break;
            case 2:
                popStack(&s);
                break;
            case 3:
                traverseStack(&s);
                break;
            case 4:
                break;
            default:
                printf("invalid\n");
        }
    } while (choice != 4);
}

void queueMenu() {
    struct Queue q;
    initQueue(&q);
    int choice, value;
    
    do {
        printf("\nqueue menu\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. traverse\n");
        printf("4. exit\n");
        printf("choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("value: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                traverseQueue(&q);
                break;
            case 4:
                break;
            default:
                printf("invalid\n");
        }
    } while (choice != 4);
}

int main() {
    int choice;
    
    do {
        printf("\nmain menu\n");
        printf("1. stack\n");
        printf("2. queue\n");
        printf("3. exit\n");
        printf("choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                stackMenu();
                break;
            case 2:
                queueMenu();
                break;
            case 3:
                break;
            default:
                printf("invalid\n");
        }
    } while (choice != 3);
    
    return 0;
}