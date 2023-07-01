TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[0]);
    int mid = 0;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == preorder[0]) {
            mid = i;
            break;
        }
    }
    vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + mid + 1);
    vector<int> preorderRight(preorder.begin() + mid + 1, preorder.end());
    vector<int> inorderLeft(inorder.begin(), inorder.begin() + mid);
    vector<int> inorderRight(inorder.begin() + mid + 1, inorder.end());


    root->left = buildTree(preorderLeft, inorderLeft);
    root->right = buildTree(preorderRight, inorderRight);

    return root;
}