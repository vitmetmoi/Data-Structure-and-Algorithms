#include<stdio.h>
#include<stdlib.h>

struct student{
int msv,grade;
struct student* next;
};

struct student* create(int msv,int grade){
    struct student* std = (struct student*)malloc(sizeof(struct student));
    std ->msv = msv;
    std->grade = grade;
    std->next = NULL;
    return std;
}

void insertList(struct student** list,int msv,int grade){
    struct student* temp = *list;
    struct student* std = create(msv,grade);
        if(*list == NULL){
            *list = std;
            return;
        }

        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = std;
}

void find(struct student** list,int msvFind){
    struct student* temp = *list;

    while(temp!=NULL){
        if(temp->next == NULL){
            printf("No data");
            break;
        }

        if(temp->msv == msvFind){
            printf("%d",temp->grade);
            break;
        }
        temp = temp->next;
    }
}

int sizeList(struct student* list){
    
    int size = 0;
    while(list!=NULL){
        size++;
        list = list->next;
    }

    return size;
}

void sortList(struct student** list){
    struct student* cur = *list;
    struct student* next = cur->next;

    for(cur = *list ; cur != NULL ; cur = cur->next){
        for(next = cur->next ; next!=NULL ; next= next->next){
            if(cur->msv > next->msv){
                int temp = cur->msv;
                cur->msv = next->msv;
                next->msv = temp;

                temp = cur->grade;
                cur->grade = next->grade;
                next->grade = temp;
            }
        }
    }
}

void show(struct student* list){
while(list!=NULL){
    printf("%d %d\n",list->msv,list->grade);
    list = list->next;
}
}

int main(){
    int n,msv,grade;scanf("%d %d %d",&n,&msv,&grade);
    struct student* head = NULL;
    insertList(&head,msv,grade);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d %d",&msv,&grade);
        insertList(&head,msv,grade);
    }

    sortList(&head);
    show(head);
    system("pause");
}