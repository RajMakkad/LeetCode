class Solution{
public:
    int minCost(vector<vector<int>>& g){
        int n = g.size();
        int m = g[0].size();
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};

        queue<pair<int,int>> q;
        vector<vector<int>> cost(n,vector<int>(m,1e9));
        cost[0][0] = 0;
        q.push({0,0});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                int cnt = 0;
                if(g[x][y] != i + 1) cnt = 1;

                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and cost[x1][y1] > cost[x][y] + cnt){
                    cost[x1][y1] = cost[x][y] + cnt;
                    q.push({x1,y1});
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};