#include<stdio.h>
void mergesort(int A[], int low, int high);
void merge(int A[], int low, int mid, int high);
void printarray(int a[], int n);
int main(){
     int A[]={9,3,7,5,6,4,8,2};
     int n = sizeof(A)/sizeof(A[0]);
     printf("original array is:\n");
     for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
     mergesort(A,0,n-1);
     printf("sorted array is:\n");
     for (int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }


}
void mergesort(int A[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid + 1, high);
        merge(A,low,mid,high);
    }
}
void merge(int A[], int low, int mid, int high) {
    int i,j,k;
    //int b[] ={};
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = A[low + i];
    for (j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    i = 0;
    j = 0;
    k = low;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
    

        

    
        
    }


