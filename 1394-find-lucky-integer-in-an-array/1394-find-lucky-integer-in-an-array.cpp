class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mp;
        int maxi = 1;
        for(int num:arr){
            mp[num]++;
            maxi = max(maxi, num);
        }
        int result = -1;
        for(auto& [num, freq] : mp) {
            if(num == freq) {
                result = max(result, num);
            }
        }

        return result;
        
    }
};