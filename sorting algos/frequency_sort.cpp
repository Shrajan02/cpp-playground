// TC: O()
// SC: O()
#include <bits/stdc++.h>
using namespace std;

vector<int> frequencySort(vector<int>& arr, int n) {
    
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

    vector<int> res = frequencySort(arr, n);
    for (int num: res) {
        cout << num << " ";
    }

    return 0;
}
