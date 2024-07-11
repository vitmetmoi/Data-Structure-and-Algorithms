#include<iostream>
#include<fstream>

using namespace std;

struct node{
    int id;
    int mark;
    string name;
    string adress;

    node* next;
};

struct node* head = NULL; 

void show(){
    struct node *p = head;
    while(p != NULL){
        cout<<p->id<<p->mark<<p->name<<" "<<p->adress;
        p = p->next;
    }
}

void add(int id ,int mark,string name,string adress){
    struct node* ptr = new node;
    ptr->id = id;
    ptr->mark = mark;
    ptr->name = name;
    ptr->adress = adress;
    ptr->next = head;
    head = ptr;
}

int find_ammount(int mark){
    int ammount = 0;
    node* ptr = head;
    while(ptr != NULL){
        if(mark < ptr->mark){
            ammount ++;
        }
    ptr = ptr->next;
    }

    return ammount;
}


void add_to_file(int mark){
    fstream file;
    file.open("output.txt", ios::out);
    file<<"Tong so thi sinh trung tuyen: "<<find_ammount(mark)<<endl;
    struct node* ptr = head;
    while(ptr != NULL){
        if(ptr->mark > mark){
            file<<ptr->id<<" "<<ptr->mark<<" "<<ptr->name<<" "<<ptr->adress<<endl;
        }
        ptr = ptr->next;
    }

    file.close();
}

void sort_element(){
    node* cur = head;
    node* prev = cur->next;
    int n = 0;

    while(cur != NULL){
        while(prev != NULL ){
            if(prev->id < cur->id){
                int temp = cur->id;
                cur->id = prev->id;
                prev->id = temp;

                temp = cur->mark;
                cur->mark = prev->mark;
                prev->mark = temp;

                string temp_ = cur->name;
                cur->name = prev->name;
                prev->name = temp_;

                temp_ = cur->adress;
                cur->adress = prev->adress;
                prev->adress = temp_;
            }
            prev = prev->next;
        }
        cur = cur->next;
        prev = cur->next;
        n++;
        if(n == 8){
            break;
        }
    }
}

int main(){
    int n ; 
    int mark;
    string s1,s2;int num1,num2;
    
    fstream file;
    file.open("input.txt",ios::in);
    file>>n;
    file>>mark;

    for(int i = 0 ; i<n ; i++){
        file>>num1;
        file>>num2;
        file>>s1;
        file>>s2;
        add(num1,num2,s1,s2);
    }
    
    sort_element();
    add_to_file(mark);
    file.close();
    system("pause");
}