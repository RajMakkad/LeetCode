// using priority queue.
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        vector<int> need(n + 1,1e9);
        vector<pair<int,int>> g[n + 1];

        for(auto &i:times) g[i[0]].push_back({i[1],i[2]});
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

        q.push({0,k});
        need[k] = 0;
        while(!q.empty()){
            int node = q.top().second;
            q.pop();

            for(auto &i:g[node]){
                int t = i.second; // weight
                if(need[i.first] > need[node] + t){
                    need[i.first] = need[node] + t;
                    q.push({need[i.first],i.first});
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            ans = max(ans,need[i]);
        }

        return ans == 1e9 ? -1 : ans;
    }
};