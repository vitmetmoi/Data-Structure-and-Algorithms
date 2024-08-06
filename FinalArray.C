#include<stdio.h>
#include<stdlib.h>

int SoLuongThiSinhTrungTuyen(int arr2[], int n, int grade) {
    int ammount = 0;
    for(int i = 0; i < n; i++) {
        if(arr2[i] >= grade) {
            ammount++;
        }
    }
    return ammount;
}

void show(int arr1[], int arr2[], char *arr3, char *arr4, int n, int grade) {
    for(int i = 0; i < n; i++) {
        if(arr2[i] >= grade) {
            printf("%d %d %s %s \n", arr1[i], arr2[i], &arr3[i*50], &arr4[i*50]);
        }
    }
}

int main() {
    int n, grade;
    scanf("%d %d", &n, &grade);
    
    int *arr1 = (int*)malloc(n * sizeof(int));
    int *arr2 = (int*)malloc(n * sizeof(int));
    char *arr3 = (char*)malloc(n * 50 * sizeof(char));
    char *arr4 = (char*)malloc(n * 50 * sizeof(char));
    
    if (!arr1 || !arr2 || !arr3 || !arr4) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d %49s %49s", &arr1[i], &arr2[i], &arr3[i*50], &arr4[i*50]);
    }

    printf("Tong so thi sinh trung tuyen: %d\n", SoLuongThiSinhTrungTuyen(arr2, n, grade));
    show(arr1, arr2, arr3, arr4, n, grade);

    free(arr1);
    free(arr2);
    free(arr3);
    free(arr4);

    return 0;
}