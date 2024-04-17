#include<stdio.h>
int iterative_binary_search(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == target) {
            return mid; // Target found, return index
        } else if (arr[mid] < target) {
            low = mid + 1; // Discard left half
        } else {
            high = mid - 1; // Discard right half
        }
    }
    
    return -1; // Target not found
}

int main() {
    int arr[] = {1, 6,7,3,5,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    int index = iterative_binary_search(arr, n, target);
    if (index != -1) {
        printf("Element %d found at index %d\n", target, index);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}