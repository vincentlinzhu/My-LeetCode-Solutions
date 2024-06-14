bool search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int m;
    while (l <= r) {
        m = (r - l)/2 + l;
        if (nums[m] == target) return true;
    
        if (nums[l] < nums[m]) {
            if (target > nums[m] || target < nums[l]) l = m + 1;
            else r = m - 1;
        }
        else if (nums[l] > nums[m]) {
            if (target < nums[m] || target > nums[r]) r = m - 1;
            else l = m + 1;
        } else {
            l++;
        }
    }
    return false;
}