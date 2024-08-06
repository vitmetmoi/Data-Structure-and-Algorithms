#include<iostream>
#include<fstream>
using namespace std;
int main(){
    ifstream input("input.txt");
    ofstream output("output.txt");
 
    int n;
    input >> n;
    int* arr=new int[n];
    for(int i=0;i<n;i++){
        input >> arr[i];
    }input.close();
    for(int i=0;i<n;i++){output << arr[i] << " ";}output.close();
}