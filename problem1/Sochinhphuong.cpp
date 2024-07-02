#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;cin>>n;
    double sqr = sqrt(n);
    int inter = sqr;
    if(sqr-inter == 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}