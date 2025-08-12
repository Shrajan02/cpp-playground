// TC: O(N*log(N))
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;

vector<int> bucketSort(vector<int>& arr, int n) {
    // insert arr[i] into buckets[n*arr[i]]
    int maxi = *max_element(arr.begin(), arr.end());
    vector<vector<int>> buckets(n);
    for (int num: arr) {
        int index = (1LL * n * num) / (maxi + 1); 
        buckets[index].push_back(num);
    }

    // sort buckets using comparative algo
    for (auto& bucket: buckets) {
        std::sort(bucket.begin(), bucket.end());
    }

    vector<int> result;
    for (auto& bucket: buckets) {
        for (int val: bucket) {
            result.push_back(val);
        }
    }

    return result;
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

    vector<int> res = bucketSort(arr, n);
    for (int num: res) {
        cout << num << " ";
    }

    return 0;
}
