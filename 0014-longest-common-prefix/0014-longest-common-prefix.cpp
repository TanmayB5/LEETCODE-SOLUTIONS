class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ans = "";
        int k = 200;

        for (int i = 0; i < strs.size(); i++) {
            k = min(k, (int)strs[i].size());
        }

        for (int j = 0; j < k; j++) {
            for (int i = 0; i < strs.size() - 1; i++) {
                if (strs[i][j] != strs[i + 1][j]) {
                    return ans;
                }
            }
            ans += strs[0][j]; 
        }

        return ans;
    }
};
