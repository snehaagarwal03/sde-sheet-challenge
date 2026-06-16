#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(int index, int sum, vector<int>& arr, vector<int>& ans) {
        if (index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        // Take current element
        solve(index + 1, sum + arr[index], arr, ans);
        // Don't take current element
        solve(index + 1, sum, arr, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        solve(0, 0, arr, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> arr = {5, 2, 1};
    int N = arr.size();
    Solution obj;
    vector<int> result = obj.subsetSums(arr, N);
    cout << "Subset sums are: ";

    for (int sum : result) {
        cout << sum << " ";
    }

    cout << endl;
    return 0;
}