class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.size() < p.size()) return res;

        vector<int> cnt(26, 0);
        for (char c : p) cnt[c - 'a']++;

        int left = 0, right = 0, needed = p.size();

        while (right < s.size()) {
            if (cnt[s[right] - 'a'] > 0) needed--;
            cnt[s[right] - 'a']--;
            right++;

            if (needed == 0) res.push_back(left);

            if (right - left == p.size()) {
                if (cnt[s[left] - 'a'] >= 0) needed++;
                cnt[s[left] - 'a']++;
                left++;
            }
        }
        return res;
    }
};
