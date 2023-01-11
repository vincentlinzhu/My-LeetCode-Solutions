bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    // preorder traversal
    if (root) {
        if (root->val == subRoot->val) {
            if (isSameTree(root, subRoot)) {
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    return false;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    // preorder traversal
    if (!p && !q) {
        return true;
    }
    if (p && q) {
        if (p->val == q->val) {
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));;
        }
    }
    return false;
}