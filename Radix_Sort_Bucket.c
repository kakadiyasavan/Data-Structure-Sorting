#include <stdio.h>
#include <stdlib.h>

#define BASE 10

// Function to get the maximum value in an array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to perform counting sort based on the digit represented by exp
void countSort(int arr[], int n, int exp) {
    int output[n];  // Output array
    int count[BASE] = {0};  // Count array for base 10
    
    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % BASE]++;
    }
    
    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < BASE; i++) {
        count[i] += count[i - 1];
    }
    
    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % BASE] - 1] = arr[i];
        count[(arr[i] / exp) % BASE]--;
    }
    
    // Copy the output array to arr[], so that arr[] contains the sorted numbers
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to implement Radix Sort
void radixSort(int arr[], int n) {
    // Find the maximum number to know the number of digits
    int max = getMax(arr, n);
    
    // Do counting sort for every digit. The exp is 10^i where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= BASE) {
        countSort(arr, n, exp);
    }
}

// Utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    radixSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
