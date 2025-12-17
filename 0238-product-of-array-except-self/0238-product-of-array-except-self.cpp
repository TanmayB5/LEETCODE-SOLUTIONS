class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int prod = 1;
        int prod0 = 0;
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                cnt0++;
            } else {
                prod *= nums[i];
            }
        }
        if (cnt0 > 1) {
            return ans;
        } else if (cnt0 == 1) {
            for (int j = 0; j < n; j++) {
                if (nums[j] != 0) {
                    ans[j] = 0;
                } else {
                    ans[j] = prod;
                }
            }
        } else {
            for(int k=0;k<n;k++){
                ans[k] = prod/nums[k];
            } 
        }
        return ans;
    }
};