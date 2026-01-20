#include <stdio.h>

int minidx(int arr[], int start, int n) {
    if (start == n - 1)
        return start;

    int minIndex = minidx(arr, start + 1, n);

    if (arr[start] < arr[minIndex])
        return start;
    else
        return minIndex;
}

void selectsortrecur(int arr[], int start, int n) {
    if (start >= n - 1)
        return;

    int minIndex = minidx(arr, start, n);

    // Swap if needed
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    selectsortrecur(arr, start + 1, n);
}

int main() {
    int transactions[] = {1054, 210, 987, 432, 56, 789};
    int n = sizeof(transactions) / sizeof(transactions[0]);

    selectsortrecur(transactions, 0, n);

    printf("Sorted Transaction IDs:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", transactions[i]);

    return 0;
}
