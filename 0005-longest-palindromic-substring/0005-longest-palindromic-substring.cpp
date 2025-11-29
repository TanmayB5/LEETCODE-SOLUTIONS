class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1;
        int st = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n-1; i >=0; i--) {
            for (int j = 1; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;

                    if (len < j - i + 1) {
                        len = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st, len);
    }
};