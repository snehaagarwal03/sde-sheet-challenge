#include <iostream>
using namespace std;

class Solution {
public:
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color, int col) {
        for (int k = 0; k < graph.size(); k++) {
            if (graph[node][k] == 1 &&
                color[k] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>>& graph, vector<int>& color, int m) {
        if (node == graph.size()) return true;
        for (int col = 1; col <= m; col++) {
            if (isSafe(node, graph, color, col)) {
                color[node] = col;
                if (solve(node + 1, graph, color, m)) return true;
                color[node] = 0;
            }
        }
        return false;
    }

    bool graphColoring(vector<vector<int>>& graph, int m) {
        int n = graph.size();
        vector<int> color(n, 0);
        return solve(0, graph, color, m);
    }
};

int main() {
    vector<vector<int>> graph = {
        {0,1,1,1},
        {1,0,1,0},
        {1,1,0,1},
        {1,0,1,0}
    };

    int m = 3;
    Solution obj;
    if(obj.graphColoring(graph, m))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}