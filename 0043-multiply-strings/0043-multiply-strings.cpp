class Solution {
public:
    string multiply(string num1, string num2) {
        long long n1 = 0, n2 = 0;

        int i = 0;
        bool neg1 = false, neg2 = false;

        if (num1[0] == '-') {
            neg1 = true;
            i = 1;
        }
        for (; i < num1.size(); i++)
            n1 = n1 * 10 + (num1[i] - '0');

        i = 0;
        if (num2[0] == '-') {
            neg2 = true;
            i = 1;
        }
        for (; i < num2.size(); i++)
            n2 = n2 * 10 + (num2[i] - '0');

        long long val = n1 * n2;
        if (neg1 ^ neg2) val = -val;

        if (val == 0) return "0";

        string ans = "";
        bool neg = val < 0;
        if (neg) val = -val;

        while (val > 0) {
            ans.push_back((val % 10) + '0');
            val /= 10;
        }

        if (neg) ans.push_back('-');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
