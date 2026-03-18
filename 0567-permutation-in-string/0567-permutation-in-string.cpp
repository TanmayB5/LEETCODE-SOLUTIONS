class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        int n = s1.size();
        int m = s2.size();

        if(n > m) return false;

        sort(s1.begin(), s1.end());

        for(int i = 0; i <= m-n; i++){

            string s = s2.substr(i, n);

            sort(s.begin(), s.end());

            if(s == s1)
                return true;
        }

        return false;
    }
};