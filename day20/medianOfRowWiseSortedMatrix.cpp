#include <iostream>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>>& matrix, int m, int n) {
        int low = INT_MAX;
        int high = INT_MIN;
        for (int i = 0; i < m; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n - 1]);
        }

        int req = (m * n) / 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int i = 0; i < m; i++) {
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            if (count <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 8},
        {2, 3, 4},
        {1, 2, 5}
    };

    int m = matrix.size();
    int n = matrix[0].size();
    Solution obj;
    cout << "Median = " << obj.median(matrix, m, n) << endl;
    return 0;
}