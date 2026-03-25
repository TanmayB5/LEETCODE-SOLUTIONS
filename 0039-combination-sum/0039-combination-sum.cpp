class Solution {
public:
    void dfs(const vector<int>& candidates, int target, vector<vector<int>>& ans,int i, vector<int>subset){
        if(target == 0){
            ans.push_back(subset);
            return;
        } 
        if (i >= candidates.size() || target < 0) {
            return;
        }
        subset.push_back(candidates[i]);
        dfs(candidates,target - candidates[i], ans,i,subset);
        
        subset.pop_back();
        
        dfs(candidates,target ,ans , i+1, subset);


    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subset;
        dfs(candidates,target,ans,0,subset);
        return ans;
    }
};