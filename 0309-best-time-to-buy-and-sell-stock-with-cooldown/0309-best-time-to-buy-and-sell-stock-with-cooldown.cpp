class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));

        for(int i=n-1;i>=0;i--){
            for(int buy = 1;buy>=0;buy--){
                if(buy==1){
                    int b = dp[i+1][0]-prices[i];
                    int cd = dp[i+1][1];
                    dp[i][1] = max(b,cd);
                } else {
                    int s = (i+2<n)? prices[i] + dp[i+2][1] : prices[i];
                   int cd = dp[i+1][0]; 
                    dp[i][0] = max(s,cd);
                }
            }
        }
        return dp[0][1];
    }
};