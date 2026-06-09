class Solution {
public:
    int mergeSort(vector<int>& nums, int low, int high) {
        // as single element has no reverse pairs
        if(low >= high) return 0;
        int mid = (low + high) / 2;

        // count reverse pairs from left half and right half
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // count reverse pairs across the two halves
        int right = mid + 1;
        for(int left = low; left <= mid; left++) {
            while(right <= high && (long long)nums[left] > 2LL * nums[right]) {
                right++;
            }
            count = count + right - (mid + 1);
        }

        vector<int> temp;
        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= high) {
            if(nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while(j <= high) {
            temp.push_back(nums[j]);
            j++;
        }

        // put merged elements back into original array
        for(int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
        return count;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};