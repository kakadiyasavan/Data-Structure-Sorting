#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    int flag = 0; // Flag to track if any swap occurred (0 = no swap, 1 = swap occurred)
    
    // Loop through the array to sort it
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        
        // Find the minimum element in the unsorted portion
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        // Swap the found minimum element with the first element
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            flag = 1;  // Set flag to 1 to indicate a swap occurred
        }
    }
    
    // If no swap occurred, the array is already sorted
    if (flag == 0) {
        printf("The array is already sorted.\n");
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 5, 4, 3};  // Example sorted array
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // Perform Selection Sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
