// Bubble Sorting 
#include<stdio.h>
// Prototype 
bubbleSort(int A[],int n);

bubbleSort(int A[],int n){
    int i,temp,j;
    for(i=0;i<n-1;i++){
        for(j=0;i<n-1-i;j++){
            if(A[j]>A[j+1]){
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}


int main(){
    int arr[]={3,10,5,2,13};
    int sizeArr=sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,sizeArr);

    return 0;
}
