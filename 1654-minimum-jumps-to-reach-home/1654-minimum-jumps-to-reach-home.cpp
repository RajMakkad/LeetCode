class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x){
        int n = 6000;
        vector<vector<int>> vis(n + 1,vector<int>(2,1e9));
        unordered_map<int,int> end;
        for(auto &i:forbidden) end[i] = 1;

        queue<pair<int,int>> q;
        if(end[0] != 1){
            vis[0][0] = vis[0][1] = 0;
            q.push({0,0});
        }

        while(!q.empty()){
            int pos = q.front().first;
            int u = q.front().second;
            q.pop();

            int forward = pos + a;
            int backward = pos - b;
            if(forward <= n and vis[forward][0] > vis[pos][u] + 1 and end[forward] != 1){
                vis[forward][0] = vis[pos][u] + 1;
                q.push({forward,0});
            }

            if(u == 1) continue;
            if(backward >= 0 and vis[backward][1] > vis[pos][u] + 1 and end[backward] != 1){
                vis[backward][1] = vis[pos][u] + 1;
                q.push({backward,1});
            }
        }

        int ans = min(vis[x][0],vis[x][1]);
        return ans != 1e9 ? ans : -1;
    }
};