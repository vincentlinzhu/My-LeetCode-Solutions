//Recursive Answer
vector<int> v;
vector<int> preorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        v.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
    return v;
}

//Iterative Answer
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*>st;
    while (root || !st.empty()) {
        if (root) {
            ans.push_back(root -> val);
            if (root -> right) {
                st.push(root -> right);
            }
            root = root -> left;
        } else {
            root = st.top();
            st.pop();
        }
    }
    return ans;
}