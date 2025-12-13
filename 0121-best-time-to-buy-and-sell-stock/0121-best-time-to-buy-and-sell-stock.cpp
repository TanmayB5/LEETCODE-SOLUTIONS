class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int i = 0;
        int j = 1;

        while(j<n){
            ans = max(ans, prices[j] - prices[i]);
            if(prices[i]>prices[j]){
                i = j;
                j = i+1;
            } else {
                j++;
            }
        }
        return ans;
    }
};