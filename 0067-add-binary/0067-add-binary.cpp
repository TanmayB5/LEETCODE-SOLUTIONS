class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int c = 0;
        int i = a.size()-1 , j = b.size()-1;

        while(i>=0 || j>=0 || c>0){
            int n1 = i>=0 ? a[i]-'0' : 0;
            int n2 = j>=0 ? b[j]-'0' : 0;

            int sum = n1 + n2 + c;
            res += (sum%2) + '0';
            c = sum/2;
            i--;
            j--;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};