class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);  // A complete permutation
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[start], nums[i]);       // Choose
            backtrack(nums, start + 1);        // Explore
            swap(nums[start], nums[i]);       // Un-choose (backtrack)
        }
    }
};
