class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> target_set;
        int n = matrix[0].size();

        // Initialize target_set with values {1, 2, ..., n}
        for (int i = 1; i <= n; i++) {
            target_set.insert(i);
        }

        // Check rows
        for (int i = 0; i < n; i++) {
            unordered_set<int> row_set(matrix[i].begin(), matrix[i].end());
            if (row_set != target_set) {
                return false;
            }
        }

        // Check columns
        for (int j = 0; j < n; j++) {
            unordered_set<int> col_set;
            for (int i = 0; i < n; i++) {
                col_set.insert(matrix[i][j]);
            }
            if (col_set != target_set) {
                return false;
            }
        }

        return true;
    }
};
