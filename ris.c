#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inssort(int arr[],int i, int n) {
    if (i==n) return;
        int j = i;
        while (j > 0 && arr[j-1] > arr[j]) {
            swap(&arr[j-1], &arr[j]);
            j--;
        }
    inssort(arr,i+1,n);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {11, 72, 25, 24, 64};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    inssort(arr,0,n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}