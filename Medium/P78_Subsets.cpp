//His Version:
void dfs(int i, vector<int>& nums, vector<vector<int>>& res, vector<int>& subset) {
    if (i >= nums.size()) {
        res.push_back(subset);
        return;
    }

    subset.push_back(nums[i]);
    dfs(i + 1, nums, res, subset);

    subset.pop_back();
    dfs(i + 1, nums, res, subset);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> subset;
    dfs(0, nums, res, subset);  
    return res;
}

// My version:
void dfs(vector<int>& nums, set<vector<int>>& s) {
    if (nums.size() == 0) {
        if (s.count(nums) == 0) {
            s.insert(nums);
        }
        return;
    }

    if (s.count(nums) != 0) {
        return;
    }

    s.insert(nums);
    vector<int> v;
    for (int i = 0; i < nums.size(); i++) {
        vector<int> x(nums.begin(), nums.end() - (nums.size() - i));
        vector<int> y(nums.begin() + i + 1, nums.end());
        v.insert(v.begin(), x.begin(), x.end());
        v.insert(v.end(), y.begin(), y.end());
        dfs(v, s);
        v.clear();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    set<vector<int>> s;
    vector<vector<int>> res;
    dfs(nums, s);
    for (auto element : s) {
        res.push_back(element);
    }   
    return res;
}