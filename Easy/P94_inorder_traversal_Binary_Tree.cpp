// Recursive Approach:
void dfs(TreeNode* root, vector<int>& v) {
    if (root != NULL) {
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    dfs(root, res);
    return res;
}

// Iterative Approach:
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;
    stack<TreeNode*> s;
    while (!s.empty() || curr != NULL) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        } else {
            curr = s.top();
            res.push_back(curr->val);
            s.pop();
            curr = curr->right;
        }
    }

    return res;
}