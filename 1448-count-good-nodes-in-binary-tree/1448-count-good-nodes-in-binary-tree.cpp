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
    int goodNodes(TreeNode* root) {
        if(!root)return 0;
        int count = 0;
        checknodes(root, count, root->val);
        return count;
    }

private:
    void checknodes(TreeNode* node,int &count,int maxnode ){
        if(!node) return;
        if(node->val>= maxnode){
            maxnode = node->val;
            count++;
            }
        checknodes(node->left,count, maxnode);
        checknodes(node->right, count, maxnode);
        return;
    }
};