class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> numWithIndex;
        
        // Create a vector of pairs (number, index)
        for (int i = 0; i < n; i++) {
            numWithIndex.push_back({nums[i], i});
        }
        
        // Sort the vector of pairs
        sort(numWithIndex.begin(), numWithIndex.end());
        
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            int sum = numWithIndex[left].first + numWithIndex[right].first;
            
            if (sum == target) {
                return {numWithIndex[left].second, numWithIndex[right].second};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        
        return {}; // No solution found
    }
};