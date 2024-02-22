#include "function2.h"

std::vector<int> generateFibonacci(int n) {
    std::vector<int> fibSeries;

    if (n <= 0)
        return fibSeries;

    fibSeries.push_back(0);
    if (n == 1)
        return fibSeries;

    fibSeries.push_back(1);
    if (n == 2)
        return fibSeries;

    for (int i = 2; i < n; ++i) {
        int nextFib = fibSeries[i - 1] + fibSeries[i - 2];
        fibSeries.push_back(nextFib);
    }

    return fibSeries;
}
