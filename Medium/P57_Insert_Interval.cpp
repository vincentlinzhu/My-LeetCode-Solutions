//Method 1:
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
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    // find the interval that has the largest point (start or end) less than new.
    // then check does the new start start inside the next interval or outside
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] > newInterval[0]) {
            // insert in between
            intervals.insert(intervals.begin() + i, newInterval);
        }
    }

    return merge(intervals);
}

//Method 2:
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++) {
        if (intervals[i][0] > newInterval[1]) {
            //insert
            res.push_back(newInterval);
            vector<vector<int>> v (intervals.begin() + i, intervals.end());
            res.insert(res.end(), v.begin(), v.end());
            return res;
        } else if (intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
        } else {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }
    }

    res.push_back(newInterval);

    return res;
}