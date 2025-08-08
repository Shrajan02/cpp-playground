// TC: O(N*logN)
// SC: O(logN)
#include <bits/stdc++.h>
using namespace std;

void min_heapify(vector<int>& arr, int i) {
    int n = arr.size();
    int left = 2*i + 1, right = 2*i + 2;
    int smallest = i;

    // left child
    if (left < n && arr[i] > arr[left]) {
        smallest = left;
    }
    
    // right child
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);
        min_heapify(arr, smallest); // bubble up
    }
}

vector<int> heapSort(vector<int>& arr, int n) {
    // build min-heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(arr, i);
    }

    // extract smallest from min-heap
    vector<int> res;
    while (!arr.empty()) {
        swap(arr[0], arr.back());
        res.push_back(arr.back());
        arr.pop_back();
        min_heapify(arr, 0);
    }

    return res;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }

    int n = arr.size();
    vector<int> res = heapSort(arr, n);
    for (int num: res) {
        cout << num << " ";
    }

    return 0;
}