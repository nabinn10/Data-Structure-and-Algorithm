#include <stdio.h>

int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x) {
            return m;
        }

        // If x greater, ignore left half
        if (arr[m] < x) {
            l = m + 1;
        }
        // If x is smaller, ignore right half
        else {
            r = m - 1;
        }
    }

    // If we reach here, then the element was not present
    return -1;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n, x;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sortArray(arr, n); // Sort the array before binary search
    printf("Enter the element to search (Binary Search): ");
    scanf("%d", &x);
    int result = binarySearch(arr, 0, n - 1, x);
    if (result != -1) {
        printf("Element is present at index %d\n", result);
    } else {
        printf("Element is not present in array\n");
    }
    return 0;
}
