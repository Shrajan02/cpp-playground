// TC: O(d * (N + b)) 
// SC: O(N + b)
// where, d -> number of digits, b -> range (10 for decimal)
#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(const vector<int>& arr, int n, int exp) {
    vector<int> res(n);  // N
    vector<int> frequency(10, 0);  // b

    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        frequency[digit]++;
    }
    for (int i = 1; i < 10; i++) {
        frequency[i] += frequency[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        int index = --frequency[digit];
        res[index] = arr[i];
    }

    return res;
}

void radixSort(vector<int>& arr, int n) {
    int maxi = *max_element(arr.begin(), arr.end());

    // apply counting sort on every digit starting from LSD
    for (int exponent = 1; maxi / exponent > 0; exponent *= 10) {
        arr = countSort(arr, n, exponent);  // 1, 10, 100 ,..
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

    radixSort(arr, n);
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
