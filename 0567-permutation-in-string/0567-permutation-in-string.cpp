class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);

        if (n > m)
            return false;

        for (int i = 0; i < n; i++) {
            c1[s1[i] - 'a']++;
        }

        for (int j = 0; j < n; j++) {
            c2[s2[j] - 'a']++;
        }
        if (c1 == c2) {
            return true;
        }

        for (int i = n; i < m; i++) {
            c2[s2[i] - 'a']++;
            c2[s2[i - n] - 'a']--;

            if (c1 == c2) {
                return true;
            }
        }
        return false;
    }
};