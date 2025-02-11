#include<stdio.h>

void selectSort(int arr[],int n,int m){
        for(int i = 0 ; i < m ; i ++){
            int maxIndex = i;
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] > arr[maxIndex]){
                    maxIndex = j;
                }
            }
                int temp = arr[i];
                arr[i] = arr[maxIndex];
                arr[maxIndex] = temp;
        }
    
}

void bubbleSort(int arr[],int n,int m){
    for(int i = 0 ; i<m ; i++){
        for(int j = 0 ; j<n-i-1 ; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertSort(int arr[],int n,int m){
    for(int i = 0 ; i < m ; i++){
        for(int j = i ; j >0 ; j--){
            if(arr[j] > arr[j-1]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int particiant(int arr[],int low ,int high){
    int pivot = high;
    int i = low - 1;
    for(int j = low ; j < high ; j ++){
        if(arr[j] > arr[pivot]){
            i ++ ;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    i++;
    int temp = arr[i];
    arr[i] = arr[pivot];
    arr[pivot] = temp;

    return i;
}

void QuickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = particiant(arr,low,high);
        QuickSort(arr,low,pivot-1);
        QuickSort(arr,pivot+1,high);
    }
}




void show(int arr[],int n){
    for(int i = 0 ; i < n ; i ++){
        printf("%d ",arr[i]);
    }
}


int main(){

    FILE *file;
    file = fopen("data.txt","r");
    int n;
    fscanf(file,"%d ",&n);int arr[n];
    for(int i = 0 ; i <n ; i ++){
        int num;
        fscanf(file,"%d ",&num);
        arr[i] = num;
    }
    fclose(file);    
    //selectSort(arr,n,3);
    bubbleSort(arr,n,3);
    //insertSort(arr,n,3);
    //QuickSort(arr,0,n-1);
    show(arr,n);
}