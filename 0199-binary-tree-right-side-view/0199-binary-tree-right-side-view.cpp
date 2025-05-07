class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res; // fix 1

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int rightmostVal = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                
                // Store the last node's value in this level
                if (i == size - 1) {
                    rightmostVal = node->val;
                }

                // fix 2: only push non-null children
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(rightmostVal);
        }

        return res;
    }
};
