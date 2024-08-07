#include<stdio.h>
int maxsize;
int front = 0;
int rear = -1;

void enQueue(int arr[],int data){
    if(rear == maxsize){
        printf("Full!");
    }
    else{
        rear++;
        arr[rear] = data;
    }
}

void deQueue(int arr[]){
    if(front == maxsize){
        printf("NULL!");
    }
    else{
    arr[front] = 0;
    front++;
    }
}

int peek(int arr[]){
    return arr[front];
}

int main(){
    scanf("%d",&maxsize);
    int arr[maxsize];
    for(int i = 0 ; i < maxsize ; i++){
        int data;
        scanf("%d",&data);
        enQueue(arr,data);
    }
    deQueue(arr);
    for(int i = 0 ; i < maxsize ; i ++){
        printf("%d ",arr[i]);
    }
}