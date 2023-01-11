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