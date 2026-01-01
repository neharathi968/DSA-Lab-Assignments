#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Bubble Sort
void bubble_sort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selection_sort(int arr[], int n){
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        // Swap
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    FILE *fp;
    fp = fopen("data.txt","r");
    if(fp == NULL){
        printf("Error: data.txt not found!\n");
        return 1;
    }

    int nums[1000], nums_copy[1000];
    int num;
    for(int i = 0; i < 1000; i++){
        fscanf(fp, "%d", &num);
        nums[i] = num;
        nums_copy[i] = num;  // make a copy for selection sort
    }
    fclose(fp);

    clock_t start_time, end_time;
    double bubble_time, selection_time;

    // Bubble Sort timing
    start_time = clock();
    bubble_sort(nums, 1000);
    end_time = clock();
    bubble_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Selection Sort timing
    start_time = clock();
    selection_sort(nums_copy, 1000);
    end_time = clock();
    selection_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Save results for gnuplot
    FILE *fp1;
    fp1 = fopen("data1.txt", "w");
    if(fp1 == NULL){
        printf("Error writing data1.txt!\n");
        return 1;
    }

    // Format: index bubble_time selection_time
    fprintf(fp1, "1 %f %f\n", bubble_time, selection_time);
    fclose(fp1);

    printf("Bubble Sort Time: %f sec\n", bubble_time);
    printf("Selection Sort Time: %f sec\n", selection_time);

    return 0;
}
