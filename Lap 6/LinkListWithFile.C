#include<stdio.h>
#include<stdlib.h>

struct student{
    int msv,grade;
    char name[100],adress[100];
    struct student* next;
};

struct student* create(int msv,int grade,char *name,char *adress){
    struct student* ptr = (struct student*)malloc(sizeof(struct student));
    ptr->msv = msv;ptr->grade = grade;
    for(int i = 0 ; i < sizeof(*name);i++){
        ptr->name[i] = *(name+i);
    }
    for(int i = 0 ; i < sizeof(*adress);i++){
        ptr->adress[i] = *(adress+i);
    }
    ptr->next= NULL;
    return ptr;
}

void insertList(struct student** list,int msv,int grade,char *name , char *adress){
    student* ptr = create(msv,grade,name,adress);
    student* temp = *list;
    if(*list == NULL){
        *list = ptr;
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

void insertList_fromFile(struct student** list){
    FILE *file1;
    file1 = fopen("bai4.inp","r");
    int msv,grade;char name[100],adress[100];
    for(int i = 0 ; i < n ; i ++){
        fscanf(file1,"%d %d %s %s",&msv,&grade,name,adress);
        insertList(&(*list),msv,grade,name,adress);
    }
    fclose(file1);
}

void insertList_toFile(struct student** list,int maxGrade){
    FILE* file2;
    file2 = fopen("bai4.oup","w");
    struct student* temp = *list;
    int ammount = 0;
    while(temp!= NULL){
        if(temp->grade>=maxGrade){
            ammount++;
        }
        temp = temp->next;
    }

    temp = *list;

    while(temp!=NULL){
        if(temp->grade>=maxGrade){
        fprintf(file2,"%d %d %s %s\n",temp->msv,temp->grade,temp->name,temp->grade);
        }
    }
    fclose(file2);
}

int main(){
 


}
