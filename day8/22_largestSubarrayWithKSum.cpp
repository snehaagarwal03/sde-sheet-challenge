#include <iostream>
#include <vector>
using namespace std;

int longestZeroSumSubarray(vector<int>& arr) {
    int n = arr.size();
    int maxl = 0;

    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum = sum + arr[j];
            if(sum == 0) {
                int len = j - i + 1;
                maxl = max(maxl, len);
            }
        }
    }
    return maxl;
}

int main() {
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    cout << "Length of longest zero sum subarray: " << longestZeroSumSubarray(arr) << endl;
    return 0;
}