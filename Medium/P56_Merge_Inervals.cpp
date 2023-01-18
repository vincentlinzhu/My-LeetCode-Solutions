vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    if (intervals.size() <= 1) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), [](vector<int>& a, const vector<int>& b) {return a[0] < b[0];});
    int l = 0;
    int r = l + 1;

    while (l < intervals.size()) {
        if (r < intervals.size() && intervals[l][1] >= intervals[r][0]) {
            // left interval expands
            intervals[l][1] = max(intervals[l][1], intervals[r][1]);
            r++;
        } else {
            res.push_back(intervals[l]);
            l = r;
            r++;
        }
    }
    return res;
}