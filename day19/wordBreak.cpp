#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:

    bool solve(int index, string &s, unordered_set<string> &dict, vector<int> &dp) {
        if(index == s.size()) return true;
        if(dp[index] != -1) return dp[index];

        string word = "";
        for(int i = index; i < s.size(); i++) {
            word += s[i];
            if(dict.count(word)) {
                if(solve(i + 1, s, dict, dp))
                    return dp[index] = true;
            }
        }
        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0, s, dict, dp);
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution obj;

    if(obj.wordBreak(s, wordDict))
        cout << "True";
    else
        cout << "False";

    cout << endl;
    return 0;
}