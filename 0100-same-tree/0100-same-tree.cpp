class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return checkeverynode(p, q);
    }

private:
    bool checkeverynode(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // both null, OK
        if (!p || !q) return false; // one null, one not
        if (p->val != q->val) return false; // different values

        return checkeverynode(p->left, q->left) &&
               checkeverynode(p->right, q->right);
    }
};
