class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();
        vector<vector<char>> ans(m, vector<char>(n)); // ✅ pre-size ans

        for (int k = 0; k < n; k++) {
            int i = 0;           // ✅ use index, not char value
            int j = i + 1;

            while (i < m - 1 && j < m) {
                if (boxGrid[k][i] == '#') {
                    if (boxGrid[k][j] == '#') {
                        j++;
                    } else if (boxGrid[k][j] == '*') {
                        i = j + 1;
                        j = i + 1;
                    } else {
                        swap(boxGrid[k][i], boxGrid[k][j]);
                        i++;
                        j++;
                    }
                } else {
                    i++;
                    j++;
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = boxGrid[n - 1 - j][i]; // ✅ rotate 90° clockwise
            }
        }
        return ans;
    }
};
