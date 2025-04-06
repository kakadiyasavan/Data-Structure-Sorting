#include <stdio.h>

// Function to merge two subarrays
void merge(int arr[], int left, int right) {
    if (left >= right) {
        return; // Base case: single element or empty subarray
    }
    
    // Find the middle point
    int mid = left + (right - left) / 2;

    // Recursively sort the first and second halves
    merge(arr, left, mid);
    merge(arr, mid + 1, right);
    
    // Merge the two sorted halves
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    int leftArr[n1], rightArr[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of leftArr[]
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy any remaining elements of rightArr[]
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Given array: \n");
    printArray(arr, arr_size);
    
    merge(arr, 0, arr_size - 1);
    
    printf("\nSorted array: \n");
    printArray(arr, arr_size);
    
    return 0;
}
