class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();

        // finding the pivot - the first element from the right to left where the previous element is smaller than the next
        // element
        int pivot = -1;

        // i = n-2 because we need to compare the second last element with the last element so everytime we are comparing
        // the prev(current) element with next element
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot found, means array is in descending order then we will change it to lowest possible combination
        if(pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // After finding pivot, we need to swap it with the smallest possible number greater than pivot. Now all the elements
        // to the right of pivot are larger and in decreasing order, so the first greater element from the end of the array
        // will be swapped with pivot
        int swapIdx = -1;
        for(int i = n - 1; i > pivot; i--) {
            if(nums[i] > nums[pivot]) {
                swapIdx = i;
                break;
            }
        }
        swap(nums[pivot], nums[swapIdx]);

        // Now we need to see whether the current combination is actually the next largest permutation. If not then, as the
        // elements after the swapped element are in decreasing order we need to reverse the decreasing suffix to get
        // ascending order - the next lexographically largest possible order
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};