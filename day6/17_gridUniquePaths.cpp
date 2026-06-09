class Solution {
public: 
    int func(int r, int c, int m, int n, vector<vector<int>>& dp) {
        //founding the valid path 
        if(r == m - 1 && c == n - 1) return 1;

        //the path that doesn't contributes so zero
        if(r >= m || c >= n) return 0;

        //checking if the ans for a particular pair already exists
        if(dp[r][c] != -1) return dp[r][c];
        int down = func(r + 1, c, m, n, dp);
        int right = func(r, c + 1, m, n, dp);

        return dp[r][c] = down + right;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(0, 0, m, n, dp);
    }
};