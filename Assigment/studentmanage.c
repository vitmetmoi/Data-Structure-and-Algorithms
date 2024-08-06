#include<stdio.h>

struct student{
    char name[10];
    double point;
    int class;
};

struct node{
    struct student std;
    struct node *next;
};

struct node *head = NULL;


void add(struct student std){
    struct node *ptr = (struct node*) malloc(sizeof(struct node*));

    ptr->std = std;
    ptr->next = head;
    head = ptr;
}



void remove_std(struct student std){
    struct node *cur = head;
    struct node *prev = NULL;

   if(head->std.name == std.name){
        head = head->next;
    }
    while(strcmp(cur->std.name,std.name) == 1){
        prev = cur;
        cur = cur->next;
    }

    prev->next = cur->next;
}


void show(){
    struct node *n = head;
    while(n != NULL){
         printf("(%s) ",n->std.name);
         printf("(%d) ",n->std.class);
         printf("(%f) ",n->std.point);
        n = n->next;
    }
}

int main(){

    struct student std1,std2,std3,std4,std5;
                            strcpy(std1.name,"Duy1");
                            std1.point = 10.0;
                            std1.class = 1;
                            strcpy(std2.name,"Duy2");
                            std2.point = 10.0;
                            std2.class = 2;
                            strcpy(std3.name,"Duy3");
                            std3.point = 10.0;
                            std3.class =3;
                            strcpy(std4.name,"Duy4");
                            std4.point = 10.0;
                            std4.class = 4;
                            strcpy(std5.name,"Duy5");
                            std5.point = 10.0;
                            std5.class = 5;

    add(std1);add(std2);add(std3);add(std4); add(std5);

    remove_std(std2);   show();

}