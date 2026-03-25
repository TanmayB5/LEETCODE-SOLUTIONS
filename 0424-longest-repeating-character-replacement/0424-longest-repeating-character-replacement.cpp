class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        unordered_map<char, int> mp;
        int i = 0 , j = 0;
        int n = s.size();
        int cnt = 0;

        while (j < n) {
            mp[s[j]]++;

            cnt = max(cnt,mp[s[j]]);

            if((j-i+1) - cnt > k){
                mp[s[i]]--;
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};