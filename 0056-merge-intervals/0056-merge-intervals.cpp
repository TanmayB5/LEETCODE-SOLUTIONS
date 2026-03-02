class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return {};


        sort(intervals.begin(),intervals.end());

        int n = intervals.size();
        ans.push_back(intervals[0]);
        
        for(int i=0;i<n;i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            int last = ans.back()[1];

            if(last >= start){
                ans.back()[1] = max(last,end);
            } else {
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};