#include <iostream>
#include <vector>
#include<cmath>

using namespace std;

float* findvalue(int n12){
 float* ptr = new float[2];
    float delta = 100*100 - 4*(1-n12);
    
    if(delta< 0 ){
        cout<<"vo nghiem";
        return 0;
    }
    else if(delta==0){
        *ptr = ptr[1] = 100 / (2*1);
    }

    else{
        *ptr = (100 + sqrt(delta))/(2);
        ptr[1] = (100 - sqrt(delta))/(2);
    }

    return ptr;

}

int main() {
    float * allvalue_1 = new float[2];
    float * allvalue_2 = new float[2];

    float n1,n2; cin>>n1>>n2;
    int n = 0;vector<int> num;


    allvalue_1 = findvalue(n1);
    allvalue_2 = findvalue(n2);

        if(*allvalue_1 > allvalue_1[1]){
            float temp = *allvalue_1;
            *allvalue_1 = allvalue_1[1];
            allvalue_1[1] = temp;
        }

            if(*allvalue_2 > allvalue_2[1]){
            float temp = *allvalue_2;
            *allvalue_2 = allvalue_2[1];
            allvalue_2[1] = temp;
        }

           float mark1 = -0.98;

            int x1 = (int) *allvalue_2; 
            int x2 = (int) allvalue_2[1];

           num.push_back(x1);

            for (int i = x1 ; i <=x2 ; i++){
                num.push_back(i);
            }
            num.push_back(x2);

            cout<<*allvalue_1<<" "<<allvalue_1[1];

            int x1_ = (int) *allvalue_1; int x2_ = (int) allvalue_1[1];

            for(int i = 0 ; i < num.size() ; i++){
                cout<<num[i]<<" ";
                if(num[i] > x1_){
                    num.erase(num.begin() + i);
                }
                if(num[i] < x2_){
                    num.erase(num.begin() + i);
                }
            }

       

            cout<<num.size()<<endl;

         //   for(int i = 0 ; i < num.size() ;i++){
           //     cout<<num[i]<<" ";
            //}
            
    return 0;
}