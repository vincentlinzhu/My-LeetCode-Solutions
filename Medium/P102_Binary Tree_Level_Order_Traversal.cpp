vector<vector<int>> levelOrder(TreeNode* root) {
    //bfs of tree
    vector<vector<int>> res;
    queue<TreeNode*> q;

    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> sub;
        for (int i = 0; i < levelSize; i++) {
            if (q.front() != NULL) {
                sub.push_back(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
            }
            q.pop();
        }
        if (sub.size() != 0) {
            res.push_back(sub);            
        }
    }
    return res;
}