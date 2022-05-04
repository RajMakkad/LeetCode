int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

class Solution {
    int dfs(int x,int y,int color,vector<vector<int>> &vis,vector<vector<int>> &g){
        int n = g.size(), count = 1;
        vis[x][y] = color;

        for(int i = 0;i<4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < n and vis[x1][y1] == 0 and g[x1][y1] == 1){
                count += dfs(x1,y1,color,vis,g);
            }
        }

        return count;
    }

public:
    int largestIsland(vector<vector<int>>& g) {
        int n = g.size(), ans = 0;
        vector<vector<int>> vis(n,vector<int>(n,0));
        vector<int> v;
        v.push_back(0);
        int color = 1;

        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(g[r][c] == 1 and vis[r][c] == 0){
                    int count = dfs(r,c,color,vis,g);
                    v.push_back(count);
                    ans = max(ans,count);
                    color++;
                }
            }
        }

        for(int r = 0;r<n;r++){
            for(int c = 0;c<n;c++){
                if(g[r][c] == 1) continue;
                unordered_set<int> s;
                for(int i = 0;i<4;i++){
                    int x1 = r + dx[i];
                    int y1 = c + dy[i];
                    if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < n and g[x1][y1] == 1){
                        s.insert(vis[x1][y1]);
                    }
                }

                int sum = 1;
                for(auto i:s) sum += v[i];
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};