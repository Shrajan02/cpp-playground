// TC: O(N*logN)
// SC: O(N)
#include <bits/stdc++.h>
using namespace std;

class HeapSort {
private:
    void max_heapify(vector<int> &arr, int n, int i) {
        int left = 2*i + 1, right = 2*i + 2;
        int largest = i;

        // left child
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        // right child
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        if (largest != i) {
            std::swap(arr[i], arr[largest]);
            max_heapify(arr, n, largest); // bubble down
        }
    }

public:
    vector<int> sort(vector<int> &arr, int n) {
        // build max heap
        for (int i = n/2 - 1; i >= 0; i--) {
            max_heapify(arr, n, i);
        }

        // swap largest from heap
        vector<int> heap = arr;  
        for (int i = n - 1; i > 0; i--) {
            std::swap(heap[0], heap[i]);
            max_heapify(heap, i, 0);  // re-heapify
        }

        return heap;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }
    int n = arr.size();

    HeapSort hs;
    vector<int> res = hs.sort(arr, n);

    for (int num : res) {
        cout << num << " ";
    }

    return 0;
}
