#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low,int high){
    int pivot = high;
    int i = low-1;
    for(int j = low ; j < high;j++){
        if(arr[j]<arr[pivot]){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    i++;
    swap(&arr[i],&arr[pivot]);

    return i;

}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pi = partition(arr,low,high); 
        QuickSort(arr,pi+1,high);
        QuickSort(arr,low,pi-1);
    }
}

void show(int arr[],int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
        for(int i = 0 ; i < n ; i++){
            int num;
            scanf("%d",&num);
            arr[i] = num;
        }

    QuickSort(arr,0,n-1);
    show(arr,n);
}