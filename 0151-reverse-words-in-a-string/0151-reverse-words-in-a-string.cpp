class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;

        // Remove leading spaces
        while (l < n && s[l] == ' ') l++;

        // Remove trailing spaces
        while (r >= 0 && s[r] == ' ') r--;

        // Trimmed substring
        s = s.substr(l, r - l + 1);

        // Remove multiple spaces between words
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && s[i + 1] == ' ') {
                s.erase(i, 1);
                i--;
            }
        }

        // Reverse the entire string
        reverse(s.begin(), s.end());

        // Reverse each word to fix their order
        int start = 0;
        for (int end = 0; end <= s.size(); end++) {
            if (end == s.size() || s[end] == ' ') {
                reverse(s.begin() + start, s.begin() + end);
                start = end + 1;
            }
        }

        return s;
    }
};
