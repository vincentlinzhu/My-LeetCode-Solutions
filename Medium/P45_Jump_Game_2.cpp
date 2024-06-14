int recursiveJump(vector<int>& nums, int n) {
    for (int i = 0; i <= n; i++) {
        if (i + nums[i] >= n) {
            return i;
        }
    }

    return 0;
}
int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return 0;
    }
    
    int res = 0;
    int rec = recursiveJump(nums, n - 1);
    res++;
    while (rec != 0) {
        rec = recursiveJump(nums, rec);
        res++;
    }

    return res;
}