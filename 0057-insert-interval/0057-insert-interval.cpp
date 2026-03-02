class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        int n = interval.size();
        vector<vector<int>> ans;
        int i = 0;

        while(i<n && newInterval[0]> interval[i][1]){
            ans.push_back(interval[i]);
            i++;
        }

        while(i<n && newInterval[1]>=interval[i][0] ){
            newInterval[0] = min(newInterval[0],interval[i][0]);
            newInterval[1] = max(newInterval[1],interval[i][1]);
            i++;
        }
        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(interval[i]);
            i++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//         int n = intervals.size(), i = 0;
//         vector<vector<int>> res;

//         while (i < n && intervals[i][1] < newInterval[0]) {
//             res.push_back(intervals[i]);
//             i++;
//         }

//         while (i < n && newInterval[1] >= intervals[i][0]) {
//             newInterval[0] = min(newInterval[0], intervals[i][0]);
//             newInterval[1] = max(newInterval[1], intervals[i][1]);
//             i++;
//         }
//         res.push_back(newInterval);

//         while (i < n) {
//             res.push_back(intervals[i]);
//             i++;
//         }
//         return res;
//     }
// };