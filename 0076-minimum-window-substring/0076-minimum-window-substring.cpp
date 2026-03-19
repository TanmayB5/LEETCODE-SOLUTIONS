class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int n = s.size();
        int m = t.size();
        map<char,int> mp;
        int start = 0;
        int len = INT_MAX;

        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        if(n<m){
            return "";
        }
        int count = m;
        int i =0 , j=0;

        while(j<n){
            if(mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            j++;

            while(count == 0){
                if(len>j-i+1){
                    len = j-i+1;
                    start = i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count++;
                }
                
                i++;
            }
        }
        if(len == INT_MAX){
            return "";
        } else {
            return s.substr(start,len);
        }
        
    }
};