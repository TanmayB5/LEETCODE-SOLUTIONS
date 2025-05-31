class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses,0);
        vector<int> res;
        queue<int> q;

        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front(); q.pop();
            res.push_back(curr);
        

        for(int next:graph[curr]){
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
        }
        if(res.size() ==numCourses ){
            return res;
        } else {
            return {};
        }
    }
};