#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++) {
        int xr = 0;
        for(int j = i; j < n; j++) {
            xr = xr ^ arr[j];

            if(xr == k) count++;
        }
    }
    return count;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "Subarray Count: " << countSubarrays(arr, k) << endl;
    return 0;
}