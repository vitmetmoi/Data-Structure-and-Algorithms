#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create(int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node* insertNode(struct node* List,int data){
    if(List == NULL){
        List = create(data);
    }
    else if(data<List->data){
        List->left = insertNode(List->left,data);
    }
    else if(data>List->data){
        List->right = insertNode(List->right,data);
    }
    return List;
}

void NLR(struct node* List){
    if(List){
        printf("%d ",List->data);
        NLR(List->left);
        NLR(List->right);
    }

}

void LNR(struct node* List){
    if(List){
        LNR(List->left);
        printf("%d ",List->data);
        LNR(List->right);
    }
}

void LRN(struct node* List){
    if(List){
        LRN(List->left);
        LRN(List->right);
        printf("%d ",List->data);
    }
}



int main(){
    int n;scanf("%d",&n);struct node* head = NULL;
    for(int i = 0 ;i<n ; i++){
        int data;scanf("%d",&data);
        head = insertNode(head,data);
    }

    LRN(head);
}