void dfs(vector<int>& candidates, int target, int i, int total, vector<int>& curr, vector<vector<int>>& res) {
    if ((i >= candidates.size() || total > target) && target != total) {
        return;
    }
    if (total == target) {
        vector<int> insert(curr.begin(), curr.end());
        res.push_back(insert);
        return;
    }

    curr.push_back(candidates[i]);
    dfs(candidates, target, i + 1, total + candidates[i], curr, res);
    curr.pop_back();
    while (i + 1 < candidates.size() && candidates[i] == candidates[i + 1]) {
        i++;
    }
    dfs(candidates, target, i + 1, total, curr, res);

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    // Find the set of all the sets where the sum is equal to the target
    // Backtracking = brute force (probably recursive)
    vector<vector<int>> res;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, 0, curr, res);
    return res;
}