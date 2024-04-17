#include <stdio.h>

int partition(int a[], int low, int high) {
    int pivot, i, j, c, s2;

    pivot = a[low];
    i = low ;
    j = high;

    while (i < j) {
        while ( a[i] <= pivot){
            i++;
        }
        while (a[j] > pivot){
            j--;
        }

        if (i < j) {
            c = a[i];
            a[i] = a[j];
            a[j] = c;
        }
    }

    s2 = a[low];
    a[low] = a[j];
    a[j] = s2;
    return j;
}

void quicksort(int a[], int low, int high) {
    int pindex;

    if (low < high) {
        pindex = partition(a, low, high);
        quicksort(a, low, pindex - 1);
        quicksort(a, pindex + 1, high);
    }
}

int main() {
    int a[100] = {6, 8, 3, 1, 4, 5, 7};
    int n = 7;

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    quicksort(a, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
