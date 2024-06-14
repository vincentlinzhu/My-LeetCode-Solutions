// Bottom Up:
pair<bool, int> dfs(TreeNode* curr) {
    pair<bool, int> p;
    if (curr == NULL) {
        p.first = true;
        p.second = 0;
        return p;
    }

    pair<bool, int> l = dfs(curr->left);
    pair<bool, int> r = dfs(curr->right);

    p.first = l.first && r.first && abs(l.second - r.second) <= 1;
    p.second = 1 + max(l.second, r.second);

    return p;
}
bool isBalanced(TreeNode* root) {
    return dfs(root).first;
}

// Brute Force:
int height(TreeNode* curr) {
    if (curr == NULL) {
        return -1;
    }
    return 1 + max(height(curr->left), height(curr->right));
}
void dfs(TreeNode* curr, bool& res) {
    if (curr != NULL) {
        if (abs(height(curr->left) - height(curr->right)) > 1) {
            res = false;
        }
        dfs(curr->left, res);
        dfs(curr->right, res);
    }
}
bool isBalanced(TreeNode* root) {
    // recursion: find height of tree on the left and right and compare;
    bool res = true;
    dfs(root, res);
    return res;
}