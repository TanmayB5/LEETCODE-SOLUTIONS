class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> ls(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!ls[i]) {             // only start DFS if the node is unvisited
                dfs(isConnected, ls, i, n);
                provinces++;          // new province found
            }
        }

        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& ls, int node, int n) {
        ls[node] = true;              // mark current node as visited

        for (int j = 0; j < n; j++) {
            if (isConnected[node][j] == 1 && !ls[j]) {
                dfs(isConnected, ls, j, n);
            }
        }
    }
};
