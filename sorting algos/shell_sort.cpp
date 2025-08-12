/*
Choose a gap & sort the elements in that particular gap (n/2).
Keep halving the gap until it is 1.
Final pass (gap = 1), is merely insertion sort.
This approach reduces number of comparisons & swaps compared to regular insertion sort, especially when smaller elements are initially located near the end of array.
*/

// TC: O(N ^2)
// SC: O(1)
#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr, int n) {
    for (int gap = n / 2; gap >= 1; gap /= 2) {
        // compare elements in gap-separated subarrays
        for (int i = gap; i < n; i++) {
            // shift gap steps backward
            for (int j = i; j >= gap; j -= gap) {
                if (arr[j - gap] <= arr[j]) {
                    break;
                }
                std::swap(arr[j - gap], arr[j]);
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

    shellSort(arr, n);
    for (int num: arr) {
        cout << num << " ";
    }

    return 0;
}