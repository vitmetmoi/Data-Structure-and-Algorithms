#include <iostream>
#include <iomanip>

double harmonicSum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / i;
    }
    return sum;
}

int findLargestN(double M) {
    int N = 1;
    while (harmonicSum(N) <= M) {
        ++N;
    }
    return N - 1;
}

int main() {
    double M;
    std::cin >> M;

    if (M < 1 || M >= 10) {
        std::cout << "NULL" << std::endl;
        return 0;
    }

    int N = findLargestN(M);
    
    if (N > 0) {
        std::cout << N << std::endl;
    } else {
        std::cout << "NULL" << std::endl;
    }

    return 0;
}