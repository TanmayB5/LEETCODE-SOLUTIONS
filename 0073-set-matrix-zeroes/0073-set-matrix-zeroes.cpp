class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns

        vector<int> row(m, 1);    // Array to mark zero rows (size should be m)
        vector<int> col(n, 1);    // Array to mark zero columns (size should be n)

        // First pass: identify rows and columns to be zeroed
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 0;   // Mark the i-th row for zeroing
                    col[j] = 0;   // Mark the j-th column for zeroing
                }
            }
        }

        // Second pass: set matrix elements to zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] == 0 || col[j] == 0) {
                    matrix[i][j] = 0; // Set matrix element to zero
                }
            }
        }
    }
};
