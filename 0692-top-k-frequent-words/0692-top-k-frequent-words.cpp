class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map <string,int> mp;
        vector<pair<int,string>> arr;
        vector<string> ans;
        

        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }

        for(auto j : mp){
            arr.push_back({j.second,j.first});
        }
        sort(arr.begin(),arr.end(), [](auto &a, auto &b){
            if(a.first == b.first){
                return a.second < b.second;
            }
            return a.first > b.first;
        });

        for(int i=0;i<k;i++){
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};