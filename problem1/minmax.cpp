#include<iostream>
 
using namespace std;
 
int main(){
    int n,m,p;cin>>n;cin>>m;cin>>p;
    int max,min;
    max = n;min=n;
    if(max<m){
        max = m;
    }
    if(max <p){
        max = p;
    }
    if(min>m){
        min = m;
    }
    if(min>p){
        min = p;
    }

    
    cout<<min<<" "<<max;
}