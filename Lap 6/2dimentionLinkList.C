#include<stdlib.h>
#include<stdio.h>

struct node{
int data;
struct node* next;
struct node* prev;
};

struct node* create(struct node* prev,int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev = prev;
    ptr->next = NULL;
    return ptr;
}

void insert(struct node** list,int data){
    struct node* ptr = create(NULL,data);
    if(*list == NULL){
        *list = ptr;
        return;
    }
    struct node* temp1 = *list;
    struct node* temp2 = *list;
    
    while(temp2->next!=NULL){
        temp1 = temp2->prev;
        temp2->prev = temp1;
        temp2 = temp2->next;
    }
    ptr->prev = temp2;
    temp2->next = ptr;
}

void show(struct node* list){
    struct node* temp = list;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
}


int main(){
    struct node* head=NULL;int data;
    int n ; scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&data);
        insert(&head,data);
    }
    show(head);
}

