#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int row;
    int col;
    int value;
} Element;

typedef struct SparseMatrix {
    int numRows;
    int numCols;
    int numNonZero;
    Element *elements;
} SparseMatrix;

void createSparseMatrix(SparseMatrix *s) {
    printf("Enter number of rows: ");
    scanf("%d", &s->numRows);

    printf("Enter number of columns: ");
    scanf("%d", &s->numCols);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &s->numNonZero);

    s->elements = (Element *)malloc(s->numNonZero * sizeof(Element));
    if (s->elements == NULL) {
        printf("malloc failed\n");
        exit(1);
    }

    printf("input (row col value):\n");
    for (int i = 0; i < s->numNonZero; i++) {
        scanf("%d %d %d", &s->elements[i].row,
                         &s->elements[i].col,
                         &s->elements[i].value);
    }
}

void displayMatrix(SparseMatrix *s) {
    printf("order: %d x %d\n", s->numRows, s->numCols);
    printf("non zero elements: %d\n", s->numNonZero);

    for (int i = 0; i < s->numRows; i++) {
        for (int j = 0; j < s->numCols; j++) {
            int value = 0;
            for (int k = 0; k < s->numNonZero; k++) {
                if (s->elements[k].row == i && s->elements[k].col == j) {
                    value = s->elements[k].value;
                    break;
                }
            }
            printf("%d\t", value);
        }
        printf("\n");
    }
}

// Add two sparse matrices
void addSparseMatrices(SparseMatrix *a, SparseMatrix *b) {
    if (a->numRows != b->numRows || a->numCols != b->numCols) {
        printf("\nMatrix addition not possible (orders differ).\n");
        return;
    }

    SparseMatrix result;
    result.numRows = a->numRows;
    result.numCols = a->numCols;
    result.numNonZero = a->numNonZero + b->numNonZero;
    result.elements = (Element *)malloc(result.numNonZero * sizeof(Element));

    int k = 0;

    // Copy elements of first matrix
    for (int i = 0; i < a->numNonZero; i++) {
        result.elements[k++] = a->elements[i];
    }

    // Add elements of second matrix
    for (int i = 0; i < b->numNonZero; i++) {
        int found = 0;
        for (int j = 0; j < k; j++) {
            if (b->elements[i].row == result.elements[j].row &&
                b->elements[i].col == result.elements[j].col) {
                result.elements[j].value += b->elements[i].value;
                found = 1;
                break;
            }
        }
        if (!found) {
            result.elements[k++] = b->elements[i];
        }
    }

    result.numNonZero = k; // update actual count

    printf("\nMatrix after addition:\n");
    displayMatrix(&result);

    free(result.elements);
}

// Transpose a sparse matrix
void transposeSparseMatrix(SparseMatrix *s) {
    SparseMatrix t;
    t.numRows = s->numCols;
    t.numCols = s->numRows;
    t.numNonZero = s->numNonZero;
    t.elements = (Element *)malloc(t.numNonZero * sizeof(Element));

    for (int i = 0; i < s->numNonZero; i++) {
        t.elements[i].row = s->elements[i].col;
        t.elements[i].col = s->elements[i].row;
        t.elements[i].value = s->elements[i].value;
    }

    printf("\nTranspose of first matrix:\n");
    displayMatrix(&t);

    free(t.elements);
}

int main() {
    SparseMatrix sm1, sm2;

    printf("Enter first matrix:\n");
    createSparseMatrix(&sm1);

    printf("\nFirst matrix:\n");
    displayMatrix(&sm1);

    printf("\nEnter second matrix:\n");
    createSparseMatrix(&sm2);

    printf("\nSecond matrix:\n");
    displayMatrix(&sm2);

    // Add two matrices
    addSparseMatrices(&sm1, &sm2);

    // Transpose of first matrix
    transposeSparseMatrix(&sm1);

    free(sm1.elements);
    free(sm2.elements);

    return 0;
}