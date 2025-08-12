/*
Create a frequency array of length max_element(arr) + 1,
where each index corresponds to count of that element.
Convert it into a cumulative frequency array.
Using both these arrays, do a backward traversal over original array.
*/

// TC: O(N + maxi)
// SC: O(N + maxi)
#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int>& arr, int n) {
    int maxi = *max_element(arr.begin(), arr.end());
    vector<int> frequency(maxi + 1, 0);
    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        frequency[arr[i]]++;
    }

    for (int i = 0; i < maxi; i++)
    {
        frequency[i + 1] += frequency[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int index = --frequency[arr[i]];
        res[index] = arr[i];
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr;
    int val;
    while (cin >> val) {
        arr.push_back(val);
    }

    int n = arr.size();
    vector<int> res = countingSort(arr, n);
    for (int num : res)
    {
        cout << num << " ";
    }

    return 0;
}
