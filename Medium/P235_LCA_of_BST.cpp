TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Since it is a binary search tree, we know that the lowest common ancestor should be between p and q (or equal)
    // If there si a split, return the node where it split
    
    // if (root->val == p->val) {
    //     return p;
    // }
    // if (root->val == q->val) {
    //     return q;
    // }
    // if (root->val > p->val && root->val < q->val) {
    //     return root;
    // }
    // if (root->val < p->val && root->val > q->val) {
    //     return root;
    // }
    // if (root->val > p->val && root->val > q->val) {
    //     return lowestCommonAncestor(root->left, p, q);
    // }
    // if (root->val < p->val && root->val < q->val) {
    //     return lowestCommonAncestor(root->right, p, q);
    // }
    // return root;

    while (root != NULL) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        } else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}