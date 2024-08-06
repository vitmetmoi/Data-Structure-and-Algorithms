#include<stdio.h>

   int front = 0;
   int rear = 0;
   int itemcount = 0;
   int n;



void inqueue(int num,int *arr){
   if(rear != n){
    *(arr + rear) = num;
    rear ++;
    itemcount ++;
   }
}

void deque(int *arr){
  *(arr+front) = 0;
  front ++;
  itemcount --;
}

int main(){
    scanf("%d",&n);int arr[n]; int num;
    for(int i =0 ; i < n ; i ++){
        scanf("%d",&num);
        inqueue(num,arr);
    }

    inqueue(10,arr);

    for(int i = front ; i <rear ; i++){
        printf("%d ",*(arr+i));
    }
}