#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* left;
struct node* right;
};

struct node* create(int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}

struct node* insertList(struct node* List,int data){
    if(List == NULL){
        return create(data); 
    }
    else if(data<List->data){
        List->left = insertList(List->left,data);
    }
    else if(data>List->data){
       List->right = insertList(List->right,data);
    }
    return List;
}

void searchNLR(struct node* List,int num){
    if(List == NULL) { return;}
        if (List->data == num) {
        if (List->left)
            printf("%d ", List->left->data);
        else
            printf("NULL ");
        
        if (List->right)
            printf("%d\n", List->right->data);
        else
            printf("NULL\n");
        return;
    }
    
    
    searchNLR(List->left,num);
    searchNLR(List->right,num);
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
            LNR(List->right);
            printf("%d ",List->data);
        }
    }
int main(){
    int n;struct node* Tree = NULL;
    scanf("%d",&n);
    for(int i = 0 ; i<n ; i ++){
        int num; scanf("%d",&num);
       Tree = insertList(Tree,num);
    }
    LNR(Tree);
    

}