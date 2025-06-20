class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        dfs(0, 0, m, n, ans, matrix, vis, "right");
        return ans;
    }

private:
    void dfs(int i, int j, int m, int n, vector<int>& ans,
             vector<vector<int>>& matrix, vector<vector<int>>& vis, string dir) {
        
        ans.push_back(matrix[i][j]);
        vis[i][j] = 1;

        if (dir == "right") {
            if (j + 1 < n && vis[i][j + 1] == 0)
                dfs(i, j + 1, m, n, ans, matrix, vis, "right");
            else if (i + 1 < m && vis[i + 1][j] == 0)
                dfs(i + 1, j, m, n, ans, matrix, vis, "down");
        }
        else if (dir == "down") {
            if (i + 1 < m && vis[i + 1][j] == 0)
                dfs(i + 1, j, m, n, ans, matrix, vis, "down");
            else if (j - 1 >= 0 && vis[i][j - 1] == 0)
                dfs(i, j - 1, m, n, ans, matrix, vis, "left");
        }
        else if (dir == "left") {
            if (j - 1 >= 0 && vis[i][j - 1] == 0)
                dfs(i, j - 1, m, n, ans, matrix, vis, "left");
            else if (i - 1 >= 0 && vis[i - 1][j] == 0)
                dfs(i - 1, j, m, n, ans, matrix, vis, "up");
        }
        else if (dir == "up") {
            if (i - 1 >= 0 && vis[i - 1][j] == 0)
                dfs(i - 1, j, m, n, ans, matrix, vis, "up");
            else if (j + 1 < n && vis[i][j + 1] == 0)
                dfs(i, j + 1, m, n, ans, matrix, vis, "right");
        }
    }
};
