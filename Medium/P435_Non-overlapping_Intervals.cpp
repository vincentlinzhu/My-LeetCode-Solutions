int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // sort by start time
    // iterate through and if the interval overlaps than remove the interval that ends later.
    if (intervals.size() <= 1) {
        return 0;
    }

    sort(intervals.begin(), intervals.end());

    int count = 0;
    int l = 0; 
    int r = 1;
    while (r < intervals.size()) {
        while (intervals[l][1] > intervals[r][0]) {
            // remove interval that ends later
            count++;
            if (intervals[r][1] < intervals[l][1]) {
                l = r;
            }
            r++;
            if (r >= intervals.size()) {
                break;
            }
        }
        l = r;
        r++;
    }

    return count;
}