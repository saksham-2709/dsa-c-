#include<stdio.h>
int main(){
 int arr[100]= {9,4,5,3,0,1,5,8};
 int i,j;
 for(i=0;i<8;i++){
    for(j=i+1;j<8;j++){
        if (arr[i]>arr[j]){
            int c = arr[i];
            arr[i] = arr[j];
            arr[j] = c;
        }
    }
 }
for(int k=0;k<8;k++){
    printf("%d\t",arr[k]);
}
return 0;
}