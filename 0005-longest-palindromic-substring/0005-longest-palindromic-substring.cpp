class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int length = 0;
        int l = 0 , r = 0;
        for(int i=0;i<n;i++){

            //odd
            l = i;
            r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                if(length < r-l+1){start = l;
                length = r-l+1;
                }
                r++;
                l--;
            }

            // even
              l = i;
            r = i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(length < r-l+1){start = l;
                length = r-l+1;
                }
                r++;
                l--;
            }
        }
        return s.substr(start, length);
    }
};