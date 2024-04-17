#include<stdio.h>
int main(){
 int arr[100]= {4,2,1,5,8};
 int i,j;
 for(i=0;i<5;i++){
    for(j=i+1;j<5;j++){
        if (arr[i]>arr[j]){
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }
    }
 }
for(int k=0;k<5;k++){
    printf("%d\t",arr[k]);
}
return 0;
}