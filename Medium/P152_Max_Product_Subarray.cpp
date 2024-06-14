int maxProduct(vector<int>& nums) {
    int res = *max_element (nums.begin(), nums.end());
    int curr_max = 1;
    int curr_min = 1;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            curr_max = 1;
            curr_min = 1;
            continue;
        }
        int temp = curr_max * nums[i];
        curr_max = max({nums[i], temp, curr_min * nums[i]});
        curr_min = min({nums[i], temp, curr_min * nums[i]});
        res = max(res, curr_max);
    }

    return res;
}