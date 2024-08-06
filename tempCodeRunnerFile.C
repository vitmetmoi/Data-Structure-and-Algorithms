#include<stdio.h>
#include<stdlib.h>
int SoLuongThiSinhTrungTuyen(int arr2[],int n,int grade){
    int ammount = 0;
    for(int i = 0 ; i <n ; i++){
        if(arr2[i] >= grade){
            ammount ++;
        }
    }
}

void show(int arr1[],int arr2[],char *arr3,char *arr4,int n,int grade){
    for(int i = 0 ; i < n ;i++){
        if(arr2[i] >= grade){
            printf("%d %d %s %s \n",arr1[i],arr2[i],*(arr3 + i),*(arr4 + i));
        }
    }
}

int main(){
int n;scanf("%d",&n);int grade;scanf("%d",&grade);
int arr1[n],arr2[n];
char *arr3[n],*arr4[n];
for(int i = 0 ; i < n ;i++ ){
    scanf("%d %d %s %s",arr1[i],arr2[i],&*(arr3+i),&*(arr4+i));
}
printf("Tong so thi sinh trung tuyen: %d\n",SoLuongThiSinhTrungTuyen(arr2,n,grade));
show(arr1,arr2,*arr3,*arr4,n,grade);
}