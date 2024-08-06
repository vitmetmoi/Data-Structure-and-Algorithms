#include<iostream>

using namespace std;

int main(){
    double M,N,max,min;
    cin>>M;
    max = M;
    min = 0;
    double num = 0;
    int n = 1;

    if(M<1||M>10){
        cout<<"NULL";return 0;
    }

    while(num<max){
        num = num + 1.0 / n;
        n++;
    }

    min = max - 1.0/n;

    if(min<1){
        cout<<"1";
        return 0;
    }

    while(num>=min){
        num = num - 1.0/n;
        n--;
    }

    cout<<n;

}