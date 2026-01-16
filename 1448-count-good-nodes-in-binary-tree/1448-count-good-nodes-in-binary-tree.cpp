class Solution {
public:
    int ans = 0;

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }

    void dfs(TreeNode* root, int maxSoFar) {
        if (root == nullptr) return;

        if (root->val >= maxSoFar) ans++;

        maxSoFar = max(maxSoFar, root->val);

        dfs(root->left, maxSoFar);
        dfs(root->right, maxSoFar);
    }
};
