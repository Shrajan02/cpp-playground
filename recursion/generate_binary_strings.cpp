/* Given an integer, n. Generate all binary strings of size n without consecutive 1’s.

Examples: 
1. n = 3  
=> Output : 000 , 001 , 010 , 100 , 101 
2. n = 4 
=> Output : 0000 0001 0010 0100 0101 1000 1001 1010
*/
#include <bits/stdc++.h>
using namespace std;

class BinaryStringGenerator {
private:
    void generateBinaryString(vector<string>& result, string current, int n, bool prev) {
        // base case
        if (n == 0) {
            result.push_back(current);
            return;
        }

        generateBinaryString(result, current + '0', n - 1, false);  // 0 
    
         // prev -> TRUE if previous element was 1
        if (!prev) {
            generateBinaryString(result, current + '1', n - 1, true); // 1
        }
    }

public:
    vector<string> generate(int n) {
        vector<string> result;
        generateBinaryString(result, "", n, false);
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    BinaryStringGenerator generator;
    vector<string> result = generator.generate(n);

    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
