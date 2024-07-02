#include<iostream>
#include<math.h>
#include<cmath>
#include <iomanip>
using namespace std;

int main(){
    double a,b,x;cin>>a;cin>>b;
    if(a==0){
        cout<<"vo nghiem";
        return 0;
    }

    x = (-b)/a;

    cout<<setprecision(3)<<fixed<<x;


}