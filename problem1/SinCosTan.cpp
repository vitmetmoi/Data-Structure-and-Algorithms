#include<iostream>
#include<math.h>

using namespace std;

double take_decimal_number(double num, int n){
    int base = pow(10,n);
    double result = round(num * base) /base; 
    return result;    
}

int main(){
    double n;
    cin>>n;
    cout<<take_decimal_number(cos(n),3)<<" "<<take_decimal_number(sin(n),3)<<" "<<take_decimal_number(tan(n),3)<<" "<<take_decimal_number(1/(tan(n)),3);
}