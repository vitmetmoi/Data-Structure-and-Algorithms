#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void SelectionSort(int arr[],int n){
    for(int i = 0 ; i < n-1 ; i++){
        for(int j = i ; j < n ; j++){
            if(arr[j]<arr[i]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}

void InsertionSort(int arr[],int n){
    for(int i = 1 ; i < n-1 ; i ++){
        for(int j = i ; j > 0 ; j--){
            if(arr[j]<arr[j-1]){
                swap(&arr[j],&arr[j-1]);
            }
        }
    }
}

int partiration(int arr[],int low,int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low ; j <= high ; j ++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    i++;
    swap(&arr[i],&arr[high]);

    return i;
}

void QuickSort(int arr[],int low,int high){
    if(low < high){
    int pi = partiration(arr,low,high);

    QuickSort(arr,low,pi-1);
    QuickSort(arr,pi+1,high);
    }
}

void bbSort(int arr[],int n){
    for(int i = 0 ; i < n-1 ; i ++ )
        for(int j = 0 ; j < n ; j++){
            if(arr[j]<arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
}


void show(int arr[],int n){
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",arr[i]);
    }
}

int main(){
    int n;FILE *file;
    file = fopen("data.txt","r");
    fscanf(file,"%d",&n);int arr[n];
    for(int i = 0 ; i < n ; i ++){
        fscanf(file,"%d",&arr[i]);
    }
    fclose(file);

    bbSort(arr,n);
    show(arr,n);
}