#include<iostream>

using namespace std;

double fibonannci(int number){
    double arr[number];
    arr[0] = 1; arr[1] = 1;

    for(int i = 2 ; i < number ; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[number-1];

}

int main(){
    int number;cin>>number;
    if(number == fibonannci(number)){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
}