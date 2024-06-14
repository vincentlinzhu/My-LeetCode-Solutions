void dfs(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset) {
    if (i >= nums.size()) {
        res.push_back(subset);
        return;
    }

    subset.push_back(nums[i]);
    dfs(i + 1, nums, res, subset);

    subset.pop_back();
    while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
    }
    dfs(i + 1, nums, res, subset);
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    dfs(0, nums, res, subset); 
    return res;
}