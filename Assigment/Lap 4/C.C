#include<stdio.h>

int top = -1; 


void push(int num,int *arr){
    top ++;
    *(arr + top) = num;
}

void pop(){
    top --;
}

int peek(int *arr){
return *(arr+top);
}

int main(){
    int n ; scanf("%d",&n); int num;
    int arr[n];
    int hoanvi[n];

    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&num);
        push(num,arr);
    }

    for(int i = 0 ; i < n ; i++){
        int sum = 0;
        for(int j = 0 ; j <= arr[i] ; j ++){
            sum += j ;
        }
        hoanvi[i] = sum;
    }

    for(int i = 0 ; i < n ; i ++){
        for(int j = i ; j < n ; j++){
            if (hoanvi[i] > hoanvi[j]){
                int temp = hoanvi[i];
                hoanvi[i] = hoanvi[j];
                hoanvi[j] = temp;
            }
        }
    }

    for(int i = 0 ; i<n ; i ++){
        printf("%d ",hoanvi[i]);
    }
}