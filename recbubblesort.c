#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[],int n){
    for (int j=0;j<n-1;j++){
            if(arr[j] > arr[j+1]){ swap(&arr[j+1],&arr[j]);
            }
            bubblesort(arr,n-1);
    }}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {11 ,82, 72, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubblesort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}