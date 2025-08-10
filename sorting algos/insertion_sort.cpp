#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& arr, int n) {
    // inserting the element into its correct position 
    // i -> unsorted portion (current element) 
    // j -> sorted portion (backward counter)
    for (int i = 1; i < n; i++) {
        int curr = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > curr) {
                std::swap(arr[j], arr[j + 1]);  
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }
    int n = arr.size();

    insertionSort(arr, n);
    for (int num: arr) {
        cout << num << " ";
    }

    return 0;
}