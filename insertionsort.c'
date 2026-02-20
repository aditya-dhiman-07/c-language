#include <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubblesort(int arr[],int n){
    for (int i=n-1;i>=1;i--){
        int iswap = 0;
        for(int j = 0;j<i;j++){
            if(arr[j] > arr[j+1]){ swap(&arr[j+1],&arr[j]);
            iswap = 1; }
        }
        if(iswap==0){ 
            printf("k\n");
            break;
    }}
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    int arr[] = {11 ,12, 22, 25, 64};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    bubblesort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}