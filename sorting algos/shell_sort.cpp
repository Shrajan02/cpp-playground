#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int>& arr, int n) {
    
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