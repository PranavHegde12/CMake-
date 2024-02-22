#include <iostream>
using namespace std;
#include "function2.h"

int main() {
    int n = 10;
    vector<int> fibSeries = generateFibonacci(n);

    cout << "Fibonacci series up to " << n << " terms:" << endl;
    for (int fib : fibSeries) {
        cout << fib << " ";
    }
    cout << endl;

    return 0;
}
