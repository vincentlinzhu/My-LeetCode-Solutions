TreeNode* invertTree(TreeNode* root) {
    if (root) {
        if (root->left || root->right) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
    }
    return root;
}

void swap(TreeNode* &first, TreeNode* &second) {
    TreeNode* temp = first;
    first = second;
    second = temp;
}