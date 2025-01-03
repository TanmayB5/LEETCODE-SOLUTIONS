class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int, int>map;
        
        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }
        for(int j=0;j<nums.size();j++){
            int diff = target - nums[j];
            if(map.count(diff) && map[diff]!=j){
                return{j+1,map[diff]+1};
            } 
        }
        return {};
    }
};