int robHelper(vector<int>& nums) {
    int rob1 = 0;
    int rob2 = 0;
    for (int i = 0; i < nums.size(); i++) {
        int temp = max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }

    return rob2;
}

int rob(vector<int>& nums) {
    vector<int> temp1 (nums.begin(), nums.end() - 1);
    vector<int> temp2 (nums.begin() + 1, nums.end());
    return max({nums[0], robHelper(temp1), robHelper(temp2)});
}