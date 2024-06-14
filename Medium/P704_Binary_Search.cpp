int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (r >= l) {
        m = (r - l)/2 + l;
        if (nums[m] == target) {
            return m;
        } else if (target < nums[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return -1;
}