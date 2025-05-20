class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // Sort to handle duplicates
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, subset, res);
        return res;
    }

private:
    void dfs(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        res.push_back(subset);  // Add current subset to result

        for (int i = index; i < nums.size(); ++i) {
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1]) continue;

            subset.push_back(nums[i]);         // Choose nums[i]
            dfs(i + 1, nums, subset, res);     // Explore further
            subset.pop_back();                 // Backtrack
        }
    }
};
