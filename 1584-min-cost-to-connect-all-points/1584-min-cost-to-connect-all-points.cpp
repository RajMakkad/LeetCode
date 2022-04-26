class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p) {
        int n = p.size();
        vector<int> dist(n,1e9), inMst(n,0);

        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        dist[0] = 0;
        q.push({0,0});

        int ans = 0;

        while(!q.empty()){
            auto node = q.top();
            q.pop();
            
            if(inMst[node[1]]) continue;
            ans += node[0];
            inMst[node[1]] = 1;

            for(int i = 0;i<n;i++){
                int d = abs(p[i][0] - p[node[1]][0]) + abs(p[i][1] - p[node[1]][1]);
                if(dist[i] > d and inMst[i] == 0){
                    dist[i] = d;
                    q.push({dist[i],i});
                }
            }
        }

        return ans;
    }
};