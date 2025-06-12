class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int ans =max( nums[n-1] - nums[0],nums[0] - nums[n-1]);

        for(int i=0;i<n-1;i++){
            int temp = max(nums[i+1] - nums[i],nums[i] - nums[i+1]);
            ans = max(ans,temp);
        }
        return ans;
    }
};