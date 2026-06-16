#include <iostream>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

class Solution {
public:

    static bool comparison(Job a, Job b) {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n) {
        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
        
        for(int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        vector<int> slot(maxi + 1, -1);
        int countJobs = 0;
        int jobProfit = 0;

        for(int i = 0; i < n; i++) {
            for(int j = arr[i].dead; j > 0; j--) {
                if(slot[j] == -1) {

                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }
        return {countJobs, jobProfit};
    }
};

int main() {

    Job arr[] = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    Solution obj;
    vector<int> ans = obj.JobScheduling(arr, n);
    cout << "Jobs Done = " << ans[0] << endl;
    cout << "Maximum Profit = " << ans[1] << endl;

    return 0;
}