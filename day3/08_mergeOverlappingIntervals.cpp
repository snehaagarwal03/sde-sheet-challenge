class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> merged = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            if (merged[1] >= intervals[i][0]) {
                merged[1] = max(merged[1], intervals[i][1]);
            } else {
                res.push_back(merged);
                merged = intervals[i];
            }
        }

        res.push_back(merged);
        return res;
    }
};