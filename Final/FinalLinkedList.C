#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* create(int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = data;
        ptr->next = NULL;
        return ptr;
}

void insertLinkedList(struct node** head,int data){
    if(*head == NULL){
        *head = create(data);
        return;
    }

    struct node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = create(data);
}

void show(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

void insertNode(struct node** head,int des,int data){
    struct node* ptr = create(data);
    struct node* temp = *head;
    if(des>1){
    for(int i = 0 ; i < des - 2 ; i ++){
        temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next = ptr;
    }
    else{
    ptr->next = *head;
    *head = ptr;
    }
}

void deleteNode(struct node** head,int des){
    struct node* temp = *head;
    struct node* prev = NULL;

    for(int i = 0 ; i < des - 1 ; i ++){
        prev = temp;
        temp = temp-> next;
    }
    prev->next = temp->next;
}

void selectedSort(struct node* head){
    struct node*temp = head;
    while(temp!=NULL){
        node* min = temp;
        node* r = temp->next;
        while(r!=NULL){
            if(min->data < r->data){
                min = r;
            }
            r = r->next;
        }
        int tem = min->data;
        min->data = temp->data;
        temp->data = tem;

        temp = temp->next;
    }
}

int main(){
    int n;struct node* head = NULL;FILE *file;
     file = fopen("data.txt","r");
    fscanf(file,"%d",&n);
    for(int i = 0 ; i<n ; i++ ){
        int data; fscanf(file,"%d",&data);
        insertLinkedList(&head,data);
    }
    fclose(file);
    deleteNode(&head,3);
    show(head);

}