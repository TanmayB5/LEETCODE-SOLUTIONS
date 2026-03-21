class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();

        // Try windows with exactly 'unique' distinct characters
        for (int unique = 1; unique <= 26; unique++) {
            vector<int> freq(26, 0);
            int i = 0, j = 0;
            int currUnique = 0;      // distinct chars in window
            int countAtLeastK = 0;   // chars with freq >= k

            while (j < n) {
                // Expand right
                if (freq[s[j] - 'a'] == 0) currUnique++;
                freq[s[j] - 'a']++;
                if (freq[s[j] - 'a'] == k) countAtLeastK++;
                j++;

                // Shrink left if too many unique chars
                while (currUnique > unique) {
                    if (freq[s[i] - 'a'] == k) countAtLeastK--;
                    freq[s[i] - 'a']--;
                    if (freq[s[i] - 'a'] == 0) currUnique--;
                    i++;
                }

                // Valid window: all unique chars appear >= k times
                if (currUnique == unique && countAtLeastK == unique) {
                    ans = max(ans, j - i);
                }
            }
        }
        return ans;
    }
};