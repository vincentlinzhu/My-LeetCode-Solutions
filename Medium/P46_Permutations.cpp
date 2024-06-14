vector<vector<int>> permute(vector<int>& nums) {
    // backtracking, recursion, find the subproblem
    // how many permutations are there for 1 element, how many for 2, etc
    vector<vector<int>> res;
    if (nums.size() == 1) {
        vector<vector<int>> v;
        v.push_back(nums);
        return v;
    }

    vector<vector<int>> perms;
    int temp;
    for (int i = 0; i < nums.size(); i++) {
        temp = nums[0];
        nums.erase(nums.begin());
        perms = permute(nums);
        for (auto p : perms) {
            p.push_back(temp);
            res.push_back(p);
        }
        nums.push_back(temp);
    }

    return res;
}