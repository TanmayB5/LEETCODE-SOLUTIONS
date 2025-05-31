class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            // Update minPrice if a lower price is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            // Calculate profit and update maxProfit if it's better
            else {
                int profit = prices[i] - minPrice;
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};
