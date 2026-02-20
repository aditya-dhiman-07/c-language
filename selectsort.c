#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selectsort(int arr[],int n){
    for (int i=0;i<n-1;i++){
        int min = i;
        for(int j = i;j<n;j++){
            if(arr[j] < arr[min]) min = j; 
        }
        swap(&arr[min],&arr[i]);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectsort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}