#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int inversionCount(vector<int>& arr) {

        int n = arr.size();
        int count = 0;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                if(arr[i] > arr[j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};
    Solution sol;

    int result = sol.inversionCount(arr);
    cout << "Number of inversions: " << result << endl;

    return 0;
}