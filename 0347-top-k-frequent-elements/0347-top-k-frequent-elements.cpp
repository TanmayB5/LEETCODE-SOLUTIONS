class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> temp;
        for(auto j:mp){
            temp.push_back({j.second,j.first});
        }
        sort(temp.rbegin(),temp.rend());

        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        return ans;

    }
};