#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    double sqrt_n = sqrt(n);
 
    cout<< setprecision(3) <<fixed<< sqrt_n <<endl;
    
    return 0;
}
