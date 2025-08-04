class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
       vector<int> dp(n,0);
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return max(nums[0],nums[1]);
        }
       //from 0 to n-2
        dp[n-2] = nums[n-2];
        dp[n-3] = max(nums[n-3],nums[n-2]);
        if(n>3){
        for(int i = n-4;i>=0;i--){
            dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
            
        }
        }
        int temp1 = dp[0];
       // from 1 to n-2
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-2],nums[n-1]);
        if(n>3){
        for(int i = n-3;i>0;i--){
            dp[i] = max(dp[i+1],dp[i+2]+nums[i]);
            
        }
        }
        int temp2 = dp[1];
        int ans = max(temp1,temp2);
        return ans;
    }
};