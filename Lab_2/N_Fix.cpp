#include<iostream>
#include<fstream>
using namespace std;

int main(){
int n ; int id , mark ;string name,adress;int ammount = 0;int const_mark;

fstream file;

file.open("input.txt",ios::in);
    file>>n; int arr1[n],arr2[n]; string arr3[n],arr4[n];
    file>>const_mark;

        for(int i = 0 ; i < n ; i ++){
            file>>id>>mark>>name>>adress;
            arr1[i] = id;
            arr2[i] = mark;
            arr3[i] = name;
            arr4[i] = adress;
        }
file.close();



file.open("output.txt",ios::out);
for(int i = 0 ; i<n ; i++){
    if(arr2[i] >= const_mark){
        ammount++;
    }
}

file<<"Tong so thi sinh trung tuyen: "<<ammount<<endl;
for(int i = 0 ; i < n ; i++){
    if(arr2[i]>=const_mark){
    file<<arr1[i]<<" "<<arr2[i]<<" "<<arr3[i]<<" "<<arr4[i]<<endl;
    }
}

file.close();

}