class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int l = 0;

        for (int num : st) {

            // checking if current number is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int curr = num;
                int count = 1;
                while (st.find(curr + 1) != st.end()) {
                    curr++;
                    count++;
                }
                l = max(l, count);
            }
        }
        return l;
    }
};