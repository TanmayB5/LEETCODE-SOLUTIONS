class Solution {
public:
    vector<int> countBits(int n) {
    vector<int> dp(n+1);
    int factor = 1;

    for (int i = 1; i <= n; i++) {
        if (2 * factor == i) {
            factor = i;
        }
        dp[i] = 1 + dp[i - factor];
    }
    return dp;
}

};