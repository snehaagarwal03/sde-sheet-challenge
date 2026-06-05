//Kadane's Algo 

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //Kadane's Algo - calculating the maxSum in single traversal in O(n) instead of traversing the array again and again for all possible subarrays
        int sum = 0;
        int maxSum = INT_MIN;    
        //because if an array has all negative elements then the maxSum can't be zero
        //INT_MIN - smallest value that int can store

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            maxSum = max(maxSum, sum);

            //When the current/running sum becomes negative there is no use of adding it further,the final sum would then result in a smaller subarray sum, so reset the subarray sum to zero (basically drop that subarray)
            if(sum < 0) sum = 0;
        }
        return maxSum;  
    }
};