int dfs(TreeNode* curr, int& res) {
    if (curr == NULL) {
        return -1;
    }
    int left = dfs(curr->left, res);
    int right = dfs(curr->right, res);
    res = max(res, left + right + 2);

    return 1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    // recursion: apply function on sub trees
    int res = 0;
    int height = 0;
    height = dfs(root, res);
    return res;
}