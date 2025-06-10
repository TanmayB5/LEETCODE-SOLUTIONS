class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;

        q.push({0, 0});
        visited.insert({0, 0});

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            // If we've used all characters
            if (i + j == s3.size()) return true;

            // Try to take from s1
            if (i < m && s1[i] == s3[i + j] && !visited.count({i + 1, j})) {
                q.push({i + 1, j});
                visited.insert({i + 1, j});
            }

            // Try to take from s2
            if (j < n && s2[j] == s3[i + j] && !visited.count({i, j + 1})) {
                q.push({i, j + 1});
                visited.insert({i, j + 1});
            }
        }

        return false;
    }
};
