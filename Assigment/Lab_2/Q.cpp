#include<iostream>

using namespace std;

int main(){
    int m ; int n ; cin>>n;cin>>m;

    int p,q;cin>>p>>q;

    int arr[n][m];

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j][i];
        }
    }

 
   /*     for(int j = 0 ; j < n ; j++){
            int temp = arr[j][p-1];
            arr[j][p-1] = arr[j][q-1];
            arr[j][q-1] = temp;
    }*/


    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }

    system("pause");

}