// i used sort() function here - but the optimal solution requires to solve without using sort()

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (nums2.size() == 0) return;
        int j = 0;
        for (int i = m; i < nums1.size(); i++) {
            nums1[i] = nums2[j];
            j++;
        }
        sort(nums1.begin(), nums1.end());   
    }
};