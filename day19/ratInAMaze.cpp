#include <iostream>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>>& maze, int n, string path, vector<string>& ans, vector<vector<int>>& vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        // moving down
        if (i + 1 < n && maze[i + 1][j] == 1 && !vis[i + 1][j]) {
            vis[i][j] = 1;
            solve(i + 1, j, maze, n, path + 'D', ans, vis);
            vis[i][j] = 0;
        }

        // moving left
        if (j - 1 >= 0 && maze[i][j - 1] == 1 && !vis[i][j - 1]) {
            vis[i][j] = 1;
            solve(i, j - 1, maze, n, path + 'L', ans, vis);
            vis[i][j] = 0;
        }

        // moving right
        if (j + 1 < n && maze[i][j + 1] == 1 && !vis[i][j + 1]) {
            vis[i][j] = 1;
            solve(i, j + 1, maze, n, path + 'R', ans, vis);
            vis[i][j] = 0;
        }

        // moving up
        if (i - 1 >= 0 && maze[i - 1][j] == 1 && !vis[i - 1][j]) {
            vis[i][j] = 1;
            solve(i - 1, j, maze, n, path + 'U', ans, vis);
            vis[i][j] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>>& maze, int n) {
        vector<string> ans;
        if (maze[0][0] == 0) return ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, maze, n, "", ans, vis);
        return ans;
    }
};

int main() {
    vector<vector<int>> maze = {
        {1,0,0,0},
        {1,1,0,1},
        {1,1,0,0},
        {0,1,1,1}
    };

    int n = 4;
    Solution obj;
    vector<string> ans = obj.findPath(maze, n);

    for(auto path : ans)
        cout << path << " ";

    cout << endl;
    return 0;
}