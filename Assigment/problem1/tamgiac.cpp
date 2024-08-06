#include<iostream>

using namespace std;

int main(){
    int a,b,c;
    cin>>a;cin>>b;cin>>c;
    bool bol = false;

    if(a+b>c && a+c>b && b+c>a){
        bol = true;
    }

    if(bol == true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}