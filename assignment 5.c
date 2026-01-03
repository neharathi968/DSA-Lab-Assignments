#include <stdio.h>
#include <stdlib.h>

struct Poly {
    int coeff;
    int power;
    struct Poly *next;
};

// function to create a new node
struct Poly* newNode(int c, int p) {
    struct Poly *t = (struct Poly*)malloc(sizeof(struct Poly));
    t->coeff = c;
    t->power = p;
    t->next = NULL;
    return t;
}

// insert term at end
void insertTerm(struct Poly **head, int c, int p) {
    struct Poly *temp = newNode(c, p);
    if (*head == NULL) {
        *head = temp;
        return;
    }
    struct Poly *t = *head;
    while (t->next != NULL)
        t = t->next;
    t->next = temp;
}

// display polynomial
void display(struct Poly *p) {
    if (p == NULL) {
        printf("0\n");
        return;
    }
    while (p != NULL) {
        printf("%dx^%d", p->coeff, p->power);
        if (p->next != NULL) printf(" + ");
        p = p->next;
    }
    printf("\n");
}

// add two polynomials
struct Poly* addPoly(struct Poly *p1, struct Poly *p2) {
    struct Poly *res = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            insertTerm(&res, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            insertTerm(&res, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            insertTerm(&res, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&res, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&res, p2->coeff, p2->power);
        p2 = p2->next;
    }
    return res;
}

// subtraction: p1 - p2
struct Poly* subPoly(struct Poly *p1, struct Poly *p2) {
    struct Poly *res = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->power == p2->power) {
            insertTerm(&res, p1->coeff - p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->power > p2->power) {
            insertTerm(&res, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else {
            insertTerm(&res, -p2->coeff, p2->power);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        insertTerm(&res, p1->coeff, p1->power);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        insertTerm(&res, -p2->coeff, p2->power);
        p2 = p2->next;
    }
    return res;
}

// main
int main() {
    struct Poly *p1 = NULL, *p2 = NULL, *res = NULL;
    int c, p, n, choice;

    while (1) {
        printf("\n1. Add polynomials\n2. Subtract polynomials\n3. Exit\n");
        scanf("%d", &choice);

        if (choice == 3) break;

        printf("Enter number of terms in polynomial 1: ");
        scanf("%d", &n);
        p1 = NULL;
        for (int i = 0; i < n; i++) {
            printf("Coeff and Power: ");
            scanf("%d %d", &c, &p);
            insertTerm(&p1, c, p);
        }

        printf("Enter number of terms in polynomial 2: ");
        scanf("%d", &n);
        p2 = NULL;
        for (int i = 0; i < n; i++) {
            printf("Coeff and Power: ");
            scanf("%d %d", &c, &p);
            insertTerm(&p2, c, p);
        }

        printf("\nP1 = "); display(p1);
        printf("P2 = "); display(p2);

        if (choice == 1) {
            res = addPoly(p1, p2);
            printf("Sum = ");
            display(res);
        }
        else if (choice == 2) {
            res = subPoly(p1, p2);
            printf("Difference = ");
            display(res);
        }
    }
    return 0;
}
