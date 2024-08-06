#include<stdio.h>

struct Node{
    int data;
    int key;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

void themphantu(int key,int data){
struct Node *p = (struct Node*) malloc(sizeof(struct Node));  

p->key = key;
p->data = data;
p->next = head;

head = p;
}

struct Node* xoaphantudautien(){
    struct Node *p = head;
    head = head->next;
    return p;
}

struct Node* timphantu(int key){
    struct Node *cur = head;

    while(cur->key != key){
        if(cur == NULL){
            return NULL;
        }
        else {
            cur = cur->next;
        }
    }
    return cur;
}

void xoaphantubatky(int key){
 struct Node *prev = NULL;
 struct Node *cur = head;

 while(cur->key != key){
    prev = cur;
    cur=cur->next;
 }

 prev->next = cur->next;
    
}

void show(){
    struct Node *node = head;
    while(node != NULL){
         printf("(%d,%d) ",node->key,node->data);
        node = node->next;
    }
}

int main(){
    int key = 1;
    int data = 3333;
    themphantu(key,data);
    themphantu(2,4444);
    themphantu(4,4444);
    xoaphantubatky(2);
    show();
    printf("Done");

}
