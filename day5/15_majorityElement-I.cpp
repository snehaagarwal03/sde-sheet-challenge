class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int count1 = 0;

        // In this we are using Moore's Voting algo
        for(int i = 0; i < n; i++) {
            if(count1 == 0) {
                s = nums[i];
            }
            if(nums[i] == s) count1++;
            else count1--;
        }

        int count2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == s) {
                count2++;
            }
        }
        if(count2 > n / 2) return s;
        return -1;
    }
};