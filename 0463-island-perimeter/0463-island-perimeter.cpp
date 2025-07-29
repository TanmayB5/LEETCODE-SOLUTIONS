class Solution {
    int perimeter = 0;  // Class-level variable

public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, vis, i, j);
                    return perimeter;
                }
            }
        }

        return 0;
    }

private:
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds → contributes to perimeter
        if (i < 0 || j < 0 || i >= m || j >= n) {
            perimeter++;
            return;
        }

        // Water cell → contributes to perimeter
        if (grid[i][j] == 0) {
            perimeter++;
            return;
        }

        // Already visited → no contribution
        if (vis[i][j])
            return;

        vis[i][j] = true;

        // Recurse in all 4 directions
        dfs(grid, vis, i - 1, j);
        dfs(grid, vis, i + 1, j);
        dfs(grid, vis, i, j - 1);
        dfs(grid, vis, i, j + 1);
    }
};
