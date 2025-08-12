// TC: O(N^2)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int>& arr, int n) {
    // selecting index of the minimum 
    // i -> sorted portion (position where next smallest element should go)
    // j -> unsorted portion
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(arr[min_index], arr[i]);
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

    selectionSort(arr, n);
    for (int num: arr) {
        cout << num << " ";
    }

    return 0;
}