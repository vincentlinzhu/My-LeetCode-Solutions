vector<int> rightSideView(TreeNode* root) {
    // BFS: Level-Order Traversal find the right most element
    vector<int> v;
    queue<TreeNode*> q;
    if (root != NULL) {
        q.push(root);
        v.push_back(root->val);
    }
    while (!q.empty()) {
        int qs = q.size();
        for (int i = 0; i < qs; i++) {
            if (q.front()->left != NULL) {
                q.push(q.front()->left);
            }
            if (q.front()->right != NULL) {
                q.push(q.front()->right);
            }
            q.pop();
        }
        if (q.empty()) {
            break;
        }
        v.push_back(q.back()->val);
    }

    return v;
}