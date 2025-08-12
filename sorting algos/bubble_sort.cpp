// TC: O(N^2)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& arr, int n) {
    // bubbling up the largest element
    // i -> pass counter
    // j -> adjacent pair check
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;  
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

    bubbleSort(arr, n);
    for (int num: arr) {
        cout << num << " ";
    }

    return 0;
}