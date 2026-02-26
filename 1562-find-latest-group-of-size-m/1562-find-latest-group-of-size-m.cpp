class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size();
        vector<int> temp(n, 0);
        vector<int> grp(n, 0);
        vector<int> count(n+1,0);

        int ans = -1;
        for (int i = 0; i < n; i++) {
            int bit = arr[i]-1;
            temp[bit] = 1;

            int left = (bit > 0 && temp[bit - 1]) ? grp[bit - 1] : 0;
            int right = (bit < n - 1 && temp[bit + 1]) ? grp[bit + 1] : 0;
            int curr = left + 1 + right;

            if (left > 0) count[left]--;
            if (right > 0) count[right]--;

            
            count[curr]++;

            grp[bit - left] = curr;
            grp[bit + right] = curr;

            if(count[m]>0){
                ans = i+1;
            }
        }
        return ans;
    }
};