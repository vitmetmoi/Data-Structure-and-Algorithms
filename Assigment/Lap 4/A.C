#include<stdio.h>

int top = -1;


void push(int num,int *arr){
top ++;
*(arr + top) = num;
}

void pop(){
    top -- ;
}

int peek(int *arr){
    return *(arr + top);
}


int main(){
    int n,m;int num;
    scanf("%d",&n);scanf("%d",&m);
    int arr[n];

    for(int i = 0 ; i<n ; i ++){
        scanf("%d",&num);
        push(num,arr);
    }

    for(int i = 0 ; i < n-m ; i++){
        printf("%d ",arr[i]);
    }

    
}