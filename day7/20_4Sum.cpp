class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        //fixing the first number
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1])   //skip duplicates
                continue;
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                //two pointers for finding 3rd and 4th number
                int l = j + 1;  
                int r = n - 1;
                while(l < r) {
                    long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        //when sum == target
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        //skipping duplicates, so here we moved to duplicate
                        while(l < r && nums[l] == nums[l + 1]) {
                            l++;
                        }
                        while(l < r && nums[r] == nums[r - 1]) {
                            r--;
                        }
                        //and now move past the duplicate 
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};