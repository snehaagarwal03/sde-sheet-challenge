//sort colors - on leetcode 
// i used selection sort here but a better approach needs to be implemented as array have only 0's 1's and 2's
class Solution {
public:
    void sortColors(vector<int>& nums) {

        int n = nums.size();
        for(int i = 0; i < n - 1; i++) {
            int min = i;
            for(int j = i + 1; j < n; j++) {
                if(nums[j] < nums[min]) {
                    min = j;
                }
            }
            swap(nums[i], nums[min]);
        }     
    }
};