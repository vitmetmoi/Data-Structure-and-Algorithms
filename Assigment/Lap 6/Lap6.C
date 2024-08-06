#include<stdio.h>
#include<stdlib.h>

struct node {
int msv,grade;
struct node *next;
};


struct node* createStudent(int msv,int grade){
    struct node* student = (struct node*)malloc(sizeof(struct node));
    student->grade = grade;
    student->msv = msv;
    student->next = NULL;
    return student;
}

void insertList(struct node** list,int msv,int grade){
    struct node* student = createStudent(msv,grade);
    if(*list==NULL){
        *list = student;
        return;
    }
    struct node* temp = *list;
    while(temp->next != NULL){
        temp = temp ->next;
    }
    temp->next = student;
}

void printSearchStudent(struct node* head,int grade_find){
    struct node* temp = head;
    struct node* student_list = NULL;
    int ammount = 0;

        while(temp!=NULL){
            if(temp->grade >= grade_find){
                ammount++;
                insertList(&student_list,temp->msv,temp->grade);
            }
            temp = temp->next;
        }

        printf("Tong so sinh vien tham du ky thi cuoi ky: %d\n",ammount);

        temp = student_list;

        while(temp != NULL){
            printf("%d %d\n",temp->msv,temp->grade);
            temp = temp->next;
        }

        while(student_list!=NULL){
            struct node* dele_ele = student_list;
            student_list = student_list->next;
            free(dele_ele);
        }
}

int main(){
    int n,grade_find;
    scanf("%d %d",&n,&grade_find);
    struct node* head = NULL;


    for(int i = 0 ; i < n ; i ++){
        int msv,grade;
        scanf("%d %d",&msv,&grade);
        insertList(&head,msv,grade);
    }

    printSearchStudent(head,grade_find);

    while(head!=NULL){
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
   system("pause");
}   