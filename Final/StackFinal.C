#include<stdio.h>
int top = -1;
int maxsize;

void push(int arr[],int data){
    if(top == maxsize){
        printf("FULL!");
    }
    else{
    top++;
    arr[top] = data;
    }
}

void pop(){
    if(top == -1){
        printf("NULL");
    }
    else{
    top--;
    }
}

int peek(int arr[]){
    return arr[top];
}


int main(){
    scanf("%d",&maxsize);
    int arr[maxsize];
    int top = -1;   
    for(int i = 0 ; i < maxsize ; i ++){
        int data;
        scanf("%d",&data);
        push(arr,data);
    }

    for(int i = 0 ; i < top+1 ; i++){
        printf("%d ",arr[i]);
    }


}