#include <iostream>
using namespace std;

vector<int> maxMeetings(vector<int>& start, vector<int>& end, int n) {

    vector<pair<int, pair<int, int>>> meetings;

    // {end, {start, meeting_number}}
    for(int i = 0; i < n; i++) {
        meetings.push_back({end[i], {start[i], i + 1}});
    }

    sort(meetings.begin(), meetings.end());
    vector<int> ans;
    ans.push_back(meetings[0].second.second);
    int lastEnd = meetings[0].first;

    for(int i = 1; i < n; i++) {
        if(meetings[i].second.first > lastEnd) {
            ans.push_back(meetings[i].second.second);
            lastEnd = meetings[i].first;
        }
    }
    return ans;
}

int main() {

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};
    
    int n = start.size();
    vector<int> result = maxMeetings(start, end, n);
    cout << "Maximum meetings = " << result.size() << "\n";
    cout << "Order of meetings: ";
    for(int meeting : result) {
        cout << meeting << " ";
    }

    cout << endl;
    return 0;
}