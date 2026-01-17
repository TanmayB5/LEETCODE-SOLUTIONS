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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode* > q;
        vector<int>res;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            
            for(int i = size; i>0;i--){
                TreeNode * node = q.front();
                q.pop();
                if(node){
                    res.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            
        }
         sort(res.begin(), res.end());
            return res[k-1];
    }
};