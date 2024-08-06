#include<iostream>

using namespace std;

int main(){
    int n ;cin>>n;

    int max ;cin>>max;int ammount = 0;

    for(int i = 0 ; i < n ; i++){
        int num;
        cin>>num;
        if(num > max){
        ammount ++;
        }
    }

    cout<<ammount;
}