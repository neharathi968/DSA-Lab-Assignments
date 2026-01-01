#include <stdio.h>


int removedup(int arr[], int n, int unique[]) {
    int j = 0;
    if(n == 0) return 0;

    if(n > 0) {
        for(int i = 0; i < n; i++) {
            for(int k = i + 1; k < n; k++) { 
                if(arr[i] != arr[k]) {
                    unique[i] = arr[k];
                    break;
                }
            }
        }
    }
    return n; 

}

int main() {
    int arr[] = {1,2,3,3,5,6,7,9,10,9};
    int unique[15];
    int n = sizeof(arr) / sizeof(arr[0]);

    n = removedup(arr, n, unique);

    printf("Unique elements: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", unique[i]);
    }
    printf("\n");

    return 0;
}
