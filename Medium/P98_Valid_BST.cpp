void inorderTraversal(TreeNode* root, vector<int>& v) {
    if (root == NULL)
        return;

    inorderTraversal(root->left, v);
    v.push_back(root->val);    
    inorderTraversal(root->right, v);
}
bool isValidBST(TreeNode* root) {
    // recursion
    // Inorder Traversal and see if the vector is always increasing.
    vector<int> v;
    inorderTraversal(root, v);
    // see if vector is in order
    for (int i = 1; i < v.size(); i++) {
        if (v[i] <= v[i - 1]) {
            return false;
        }
    }
        
    return true;    
}