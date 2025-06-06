class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        int ans = 0;
        int j = 0;

        for (int i = 0; i < m && j < n; ++i) {
            if (text1[i] == text2[j]) {
                ans++;
                j++;
            } else {
                // Keep checking text1 until we find match for text2[j]
                // Reset i back one step so that next loop starts from i+1
                if (j < n && i == m - 1) {
                    i = -1;  // will become 0 in next loop
                    j++;
                }
            }
        }

        return ans;
    }
};
