class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n, false);
        queue<int> q;
        int changes = 0;

        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < connections.size(); i++) {
                int u = connections[i][0];
                int v = connections[i][1];

                // if the connection is from current to another node
                // (i.e., u → v) and we haven’t visited v yet, it needs to be reversed
                if (u == current && !visited[v]) {
                    changes++;            // wrong direction
                    visited[v] = true;
                    q.push(v);
                }
                // if the connection is from another node to current
                // (i.e., v → u), and we haven’t visited u yet, it's okay
                else if (v == current && !visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }

        return changes;
    }
};
