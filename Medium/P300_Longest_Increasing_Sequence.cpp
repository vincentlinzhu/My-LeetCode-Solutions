int lengthOfLIS(vector<int>& nums) {
    vector<int> LIS(nums.size(), 1);

    for (int i = nums.size() - 1; i >= 0; i--) {
        int j = i + 1;
        while (j < nums.size()) {
            if (nums[j] > nums[i]) {
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
            j++;
        }
    }

    int currMax = LIS[0];
    for (auto len : LIS) {
        if (len > currMax) {
            currMax = len;
        }
    }

    return currMax;
}