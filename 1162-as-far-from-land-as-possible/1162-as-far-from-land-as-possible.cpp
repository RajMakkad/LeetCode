class Solution {
public:
    int maxDistance(vector<vector<int>>& g){
        int n = g.size();

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(g[r][c] == 1){
                    q.push({r,c});
                    dist[r][c] = 0;
                }
            }
        }

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        int ans = -1;

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < n and dist[x1][y1] > dist[x][y] + 1){
                    dist[x1][y1] = dist[x][y] + 1;
                    q.push({x1,y1});
                    ans = max(ans,dist[x1][y1]);
                }
            }
        }

        return ans;
    }
};