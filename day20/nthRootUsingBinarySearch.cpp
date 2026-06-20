#include <iostream>
using namespace std;

class Solution {
public:
    int nthRoot(int n, int m) {
        int low = 1;
        int high = m;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long ans = 1;

            // calculate mid^n
            for (int i = 0; i < n; i++) {
                ans *= mid;
                if (ans > m) break;
            }
            if (ans == m) return mid;
            if (ans < m) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution obj;
    int n = 3;
    int m = 27;
    cout << "Nth Root = " << obj.nthRoot(n, m) << endl;
    return 0;
}