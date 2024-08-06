#include<iostream>

using namespace std;

bool kiem_tra(int a,int b ,int c){
    bool bol = false;
    if(a*a == b*b + c*c){
        bol = true;
    }

    if (b*b == a*a +c*c){
        bol = true;
    }

    if( c*c == a*a + b*b){
        bol = true;
    }
    return bol;
}

int main(){
    int a,b,c; cin>>a ;cin>>b;cin>>c;
    bool bol = kiem_tra(a,b,c);
    if(bol == true){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}