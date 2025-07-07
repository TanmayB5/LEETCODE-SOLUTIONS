/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root){return ans;}
        int lev = 0;

        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int size = q.size();

            for(int i=size;i>0;i--){
            TreeNode * node = q.front();
            q.pop();
             if (node) {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(lev%2!=0){
                reverse(level.begin(),level.end());
            }
            if (!level.empty()) {
                ans.push_back(level);
            }
            lev++;
        }
        return ans;
    }
};