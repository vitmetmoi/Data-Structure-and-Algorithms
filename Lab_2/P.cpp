#include<iostream>

using namespace std;

int main(){
    int n ; int p ; cin>>p;cin>>n;
    int arr[n][p];
    for(int i = 0 ; i< p ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j][i];
        }
    }

    for(int i = 0 ; i< p ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }

}