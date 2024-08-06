#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct student{
    int msv,grade;  
    char name[100],adress[100];
    struct student* next;
};

struct student* create(int msv,int grade,char *name,char *adress){
    struct student* ptr = (struct student*)malloc(sizeof(struct student));
    ptr->msv = msv;ptr->grade = grade;strcpy(ptr->name,name);strcpy(ptr->adress,adress);
    /*for(int i = 0 ; i < sizeof(*name);i++){
        ptr->name[i] = *(name+i);
    }
    for(int i = 0 ; i < sizeof(*adress);i++){
        ptr->adress[i] = *(adress+i);
    }*/
    ptr->next= NULL;
    return ptr;
}

void insertList(struct student** list,int msv,int grade,char *name , char *adress){
    struct student* ptr = create(msv,grade,name,adress);
    struct student* temp = *list;
    if(*list == NULL){
        *list = ptr;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

void show(struct student *list){
    while(list!=NULL){
        printf("%d %d %s %s\n",list->msv,list->grade,list->name,list->adress);
        list = list->next;
    }
}

void insertList_fromFile(struct student** list,int *n,int *maxGrade,char *maxAdress){
    FILE *file1;
    file1 = fopen("bai5.inp","r");
    int msv,grade;char name[100],adress[100];
    fscanf(file1,"%d %d %s",&(*n),&(*maxGrade),maxAdress);
    for(int i = 0 ; i < *n ; i ++){
        fscanf(file1,"%d %d %s %s",&msv,&grade,name,adress);
        insertList(&(*list),msv,grade,name,adress);
    }
    fclose(file1);
}

void insertList_toFile(struct student** list,int maxGrade,char *maxAdress){
    FILE* file2;
    file2 = fopen("bai5.out","w");
    struct student* temp = *list;
    int ammount = 0;
    while(temp!= NULL){
        if(temp->grade>=maxGrade && (strcmp(temp->adress,maxAdress) == 0)){
            ammount++;
        }
        temp = temp->next;
    }
    fprintf(file2,"Tinh: %s\n",maxAdress);
    fprintf(file2,"Tong so thi sinh trung tuyen: %d\n",ammount);
    temp = *list;
     while(temp!=NULL){
       if(temp->grade>=maxGrade && (strcmp(temp->adress,maxAdress) == 0)){
        fprintf(file2,"%d %d %s \n",temp->msv,temp->grade,temp->name);
        }
        temp = temp->next;  
    }
    fclose(file2);
    
}




int main(){
 int n;int maxGrade;char maxAdress[100];
 struct student* head=NULL;
 insertList_fromFile(&head,&n,&maxGrade,maxAdress);
 show(head);
 insertList_toFile(&head,maxGrade,maxAdress);
}
