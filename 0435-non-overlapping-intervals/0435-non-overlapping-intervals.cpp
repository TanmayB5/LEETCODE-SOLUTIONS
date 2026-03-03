class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(), [](auto& a ,auto& b){
           return a[1] < b[1];
        });

        int lastend = intervals[0][1];
        int ans = 0;

        for(int i=1;i<intervals.size();i++){
           int st = intervals[i][0];
            if(st < lastend){
                ans++;
            } else {
                lastend = intervals[i][1];
            }
        }
        return ans;
    }
};