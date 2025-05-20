class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(0,candidates, target,0, comb,res);
        return res;
    }


private:
    void dfs(int i,vector<int>& candidates ,int target, int sum,vector<int> &comb, vector<vector<int>> &res){
        // Base cases
        if (sum > target || i >= candidates.size()) return;

        if (sum == target) {
            res.push_back(comb);
            return;
        }

        if(sum<target){
          comb.push_back(candidates[i]);
          dfs(i,candidates, target, sum + candidates[i], comb, res);
          comb.pop_back();
          dfs(i+1,candidates, target, sum, comb ,res);
        }
        return;
    }
};