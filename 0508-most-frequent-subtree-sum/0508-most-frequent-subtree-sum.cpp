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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxfreq = 0;

        completesum(root,mp,maxfreq);
        vector<int> ans;
        for(auto& [sum,freq] : mp){
            if(freq == maxfreq){
                ans.push_back(sum);
            }
        }
        return ans;
    }

private:
    int completesum(TreeNode* root,unordered_map<int,int> &mp,int &maxfreq ){
        if(!root) return 0;

        int leftsum = completesum(root->left,mp,maxfreq);
        int rightsum = completesum(root->right,mp,maxfreq);

        int totalsum = root->val +leftsum + rightsum;
        mp[totalsum]++;
        maxfreq  = max(maxfreq,mp[totalsum]);
        return totalsum;
    }
};