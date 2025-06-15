class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> lastindex;
        for(int i=0;i<s.size();i++){
            lastindex[s[i]] = i;
        } 
        int end =0, size =0;
        vector<int>res;
        for(int i=0;i<s.size();i++){
            size++;
            end = max(end,lastindex[s[i]]);

            if(i==end){
                res.push_back(size);
                size = 0;

            }
        }
        return res;
    }
};