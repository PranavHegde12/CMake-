#include<bits/stdc++.h>
using namespace std;

template<typename T>
void bubbleSort(vector<T>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    vector<char> numbers = {'c','h','e','a','w','b','o'};
    bubbleSort(numbers);

    cout << "Sorted numbers: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout <<endl;

    return 0;
}
