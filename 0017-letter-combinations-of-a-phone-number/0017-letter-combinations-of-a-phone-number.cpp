class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        // Map digits to corresponding characters
        digitToChar = {"", "", "abc", "def", "ghi", "jkl", 
                       "mno", "pqrs", "tuv", "wxyz"};

        string current;
        dfs(0, digits, current, res);
        return res;
    }

private:
    vector<string> digitToChar;

    void dfs(int i, const string &digits, string &current, vector<string> &res) {
        if (current.size() == digits.size()) {
            res.push_back(current);
            return;
        }

        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            current.push_back(c);
            dfs(i + 1, digits, current, res);
            current.pop_back(); // backtrack
        }
    }
};
