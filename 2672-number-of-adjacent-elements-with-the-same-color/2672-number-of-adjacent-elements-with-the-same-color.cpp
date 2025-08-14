class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> temp(n, 0);
        vector<int> ans;
        int curr = 0;
        for(auto & query:queries){
            int idx= query[0];
            int color = query[1];

            if(temp[idx]!=0){
                if(idx>0 && temp[idx] == temp[idx-1]){curr--;}
                if(idx<n-1 && temp[idx] == temp[idx+1]){curr--;}
            }
            temp[idx] = color;

             if(temp[idx]!=0){
                if(idx>0 && temp[idx] == temp[idx-1]){curr++;}
                if(idx<n-1 && temp[idx] == temp[idx+1]){curr++;}
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
