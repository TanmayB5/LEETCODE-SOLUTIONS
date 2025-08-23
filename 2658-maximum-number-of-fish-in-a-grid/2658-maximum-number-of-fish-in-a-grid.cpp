class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary check first
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;

        // water or already visited
        if (grid[i][j] == 0 || vis[i][j] == 1) return 0;

        vis[i][j] = 1; // mark visited
        int ans = grid[i][j];

        // explore 4 directions
        ans += dfs(grid, vis, i-1, j);
        ans += dfs(grid, vis, i+1, j);
        ans += dfs(grid, vis, i, j-1);
        ans += dfs(grid, vis, i, j+1);

        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] > 0) {
                    ans = max(ans, dfs(grid, vis, i, j));
                }
            }
        }
        return ans;
    }
};
