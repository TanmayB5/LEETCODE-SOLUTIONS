class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ls;
        sort(candidates.begin(), candidates.end());  // Sort the array
        findCombination(0, target, ls, candidates, ans);
        return ans;
    }

    void findCombination(int i, int target, vector<int>& ls, vector<int>& arr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(ls);
            return;
        }
        
        if (i == arr.size() || target < 0) {
            return;
        }

        // Include current element
        ls.push_back(arr[i]);
        findCombination(i + 1, target - arr[i], ls, arr, ans);
        ls.pop_back();

        // Skip duplicates
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
            i++;
        }

        // Exclude current element
        findCombination(i + 1, target, ls, arr, ans);
    }
};