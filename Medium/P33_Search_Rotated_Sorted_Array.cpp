int search(vector<int>& nums, int target) {
    // apply a binary search variation to find the target
    // make sure to really think about the conditions and what to shift bacause the array is rotated
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r) {
        m = (l + r)/2;
        if (nums[m] == target) return m;
        if (nums[l] <= nums[m]) {
            if (target > nums[m] || target < nums[l]) l = m + 1;
            else r = m - 1;
        }
        else {
            if (target < nums[m] || target > nums[r]) r = m - 1;
            else l = m + 1;
        }
    }
    return -1;
}