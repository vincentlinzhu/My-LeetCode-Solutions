[#include](https://leetcode.com/problems/minimum-interval-to-include-each-query) <bits/stdc++.h>
using namespace std;

static bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}


int dp(vector<vector<int>> &intervals, vector<int> &vol, int i , int n, int sum, vector<int> &temp) {
    if(i >= n) {
        return sum;
    }
    
   
        if(intervals[i][0] > temp[1]) {
            return max(dp(intervals, vol, i + 1,n, sum + intervals[i][2], intervals[i]), dp(intervals, vol, i + 1, n, sum, temp));
        }
        else {
            return dp(intervals, vol, i + 1,n, sum, temp);
        }
    
    
}


int main() {

    vector<int> start = {10, 5, 15, 18, 30};
    vector<int> duration = {30, 12,20, 35, 35};
    vector<int> vol = {50, 51, 20, 25, 10};
    vector<int> end;
    for (int i = 0; i < start.size(); i++) {
        end.push_back(start[i] + duration[i]);
    }

    vector<vector<int>> intervals;
    for (int i = 0; i < start.size();i++) {
        intervals.push_back({start[i], end[i], vol[i]});
    }
     
    sort(intervals.begin(), intervals.end(), comp);
    int n = intervals.size();
    // for(auto x : intervals) {
    //     cout << x[0] << " " << x[1] << endl;
    // }
    // cout << endl;
    vector<int> temp = {0, 0};
    int ans = dp(intervals, vol, 0, n, 0,temp);
    cout << ans << endl;

    return 0;
}
// Now that will give TLE
// TC: O(2^N)

// Let's use some DP

int solve(vector<int>& startTime, vector<int>& endTime, vector<int>& vol) {
    int n = startTime.size();
    vector<vector<int>> jobs;
    for (int i = 0; i < n; ++i) {
        jobs.push_back({endTime[i], startTime[i], profit[i]});
    }
    sort(jobs.begin(), jobs.end());
    map<int, int> dp = {{0, 0}};
    for (auto& job : jobs) {
        int cur = prev(dp.upper_bound(job[1]))->second + job[2];
        if (cur > dp.rbegin()->second)
            dp[job[0]] = cur;
    }
    return dp.rbegin()->second;
}