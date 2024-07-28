class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ls;
        combination(0, target, ls, candidates, ans);
        return ans;
    }
    
    void combination(int i, int target, vector<int>& ls, vector<int>& arr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ls);
            return;
        }
        
        if (i == arr.size() || target < 0) {
            return;
        }
        
        // Include current element
        ls.push_back(arr[i]);
        combination(i, target - arr[i], ls, arr, ans);
        ls.pop_back();
        
        // Exclude current element
        combination(i + 1, target, ls, arr, ans);
    }
};