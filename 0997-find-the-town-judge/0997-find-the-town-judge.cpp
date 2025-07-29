class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0);   // number of people who trust i
        vector<int> outdegree(n + 1, 0);  // number of people i trusts

        for (auto& t : trust) {
            int a = t[0];
            int b = t[1];
            outdegree[a]++;
            indegree[b]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (indegree[i] == n - 1 && outdegree[i] == 0) {
                return i;  // found the judge
            }
        }

        return -1;  // no judge found
    }
};
