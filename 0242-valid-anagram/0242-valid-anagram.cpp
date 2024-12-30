class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }
        
        // Create frequency arrays for both strings
        vector<int> freq(26, 0); // Assuming only lowercase letters
        
        // Count frequencies of characters in `s` and `t`
        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        
        // Check if all frequencies are zero
        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        
        return true;
    }
};
