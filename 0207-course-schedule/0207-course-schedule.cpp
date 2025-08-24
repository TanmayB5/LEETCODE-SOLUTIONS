class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numcourses, 0);
        vector<vector<int>> graph(numcourses);
        int finished = 0;

        for (auto p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numcourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // ✅ Process all courses that are ready (i.e., indegree == 0)
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            finished++;

            for (auto next : graph[course]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return finished == numcourses;
    }
};
