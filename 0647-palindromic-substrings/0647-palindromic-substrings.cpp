class Solution {
public:

    bool ispal(string s){
        int a = s.size();
        for(int i=0;i<a/2;i++){
            if(s[i]!=s[a-i-1]){
                return false;
            }
        }
        return true;
    }

    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s.substr(i,j-i+1))){
                cnt++;
                }
            }
        }
        return cnt;
    }
};