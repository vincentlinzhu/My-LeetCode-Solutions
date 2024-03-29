int maxDepth(TreeNode* root) {
    if (root) {
        if (!root->left && !root->right) {
            return 1;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    return 0;
}