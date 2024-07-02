#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    bool bol = true;
    cin>>n;
    for(int i = 2 ; i<sqrt(n);i++){
        if(n%i==0){
            bol=false;
        }
    }

    if(bol == true){
        cout<<"co";
    }

    else{
        cout<<"khong";
    }
}