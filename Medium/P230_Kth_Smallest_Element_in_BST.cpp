void inorderTraversal(TreeNode* root, vector<int>& v, int k) {
    if (v.size() == k) {
        return;
    }
    if (root != NULL) {
        inorderTraversal(root->left, v, k);
        v.push_back(root->val);
        inorderTraversal(root->right, v, k);
    }
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> v;
    inorderTraversal(root, v, k);
    return v[k-1];
}