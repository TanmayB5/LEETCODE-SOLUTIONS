class Solution {
public:
    int trap(vector<int>& h) {
        int i=0;
        int j=h.size()-1;
        int leftmax=h[i];
        int rightmax= h[j];
        int res = 0;

        while(i<j){
            if(leftmax<rightmax){
                i++;
                leftmax = max(leftmax , h[i]);
                res += leftmax - h[i];
            } else {
                j--;
                rightmax = max(rightmax, h[j]);
                res += rightmax - h[j];
            }
        }
        return res;
    }
};