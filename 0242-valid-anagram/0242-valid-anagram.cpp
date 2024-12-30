class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are different, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }
        
        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        // Compare the sorted strings
        return s == t;
    }
};
