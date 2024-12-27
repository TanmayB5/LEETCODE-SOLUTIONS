class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      std::unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
      }
       
       //creting bucket
       int n = nums.size();
       vector<vector<int>>buckets(n+1);
       for(auto [num,freq]:mp){
        buckets[freq].push_back(num);
       }

        vector<int> result;
        for (int i = n; i > 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }     
};