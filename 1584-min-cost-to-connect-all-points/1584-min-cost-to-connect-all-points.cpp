#define pi pair<int,int>
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& p){
        int n = p.size();
        vector<pi> g[n]; // (node,edge)

        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                int e = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1]);
                g[i].push_back({j,e});
                g[j].push_back({i,e});
            }
        }

        vector<int> key(n,1e9), inMst(n,0);
        key[0] = 0;

        priority_queue<pi,vector<pi>,greater<pi>> q; // (key,node)
        q.push({0,0});

        while(!q.empty()){
            int node = q.top().second;
            inMst[node] = 1;

            q.pop();

            for(auto &i:g[node]){
                if(inMst[i.first] == 0 and key[i.first] > i.second){
                    key[i.first] = i.second;
                    q.push({key[i.first],i.first});
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++) ans += key[i];
        return ans;
    }
};