class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
       
        int res = 0;
        
        while(i<j){
           int area = min(height[j],height[i])*(j-i);
           res = max(res,area);
          
          
           if(height[j]>=height[i]){
            i++;
           } else {
            j--;
           }
           
           
           
        }
        return res;
    }
};