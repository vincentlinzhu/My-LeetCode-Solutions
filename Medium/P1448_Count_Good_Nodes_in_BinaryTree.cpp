void dfs(TreeNode* curr, int& count, int& max) {
    if (curr == NULL) {
        return;
    }

    if (curr->val >= max) { 
        count++;
        max = curr->val;
    }
    int levelMax = max;
    dfs(curr->left, count, max);
    dfs(curr->right, count, levelMax);
}

int goodNodes(TreeNode* root) {
    // recursive: how many good nodes are in the subtree
    // duplicate work can be avoided if we keep track as we go down
    // dfs
    int count = 0;
    dfs(root, count, root->val);
    return count;
}