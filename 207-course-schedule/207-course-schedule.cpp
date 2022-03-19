class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p){
        vector<int> g[n],indegree(n,0);

        for(auto &i:p){
            g[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }

        queue<int> q;
        for(int i = 0;i<n;i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> toposort;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            toposort.push_back(node);

            for(auto &i:g[node]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        return toposort.size() == n;
    }
};