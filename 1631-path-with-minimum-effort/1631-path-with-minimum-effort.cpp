#define pi pair<int, pair<int,int>>
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h){
        int n = h.size();
        int m = h[0].size();

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        priority_queue<pi,vector<pi>,greater<pi>> q;
        vector<vector<int>> effort(n,vector<int>(m,1e9));
        effort[0][0] = 0;
        q.push({0,{0,0}});

        while(!q.empty()){
            int e = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m){
                    int d = abs(h[x1][y1] - h[x][y]);
                    if(effort[x1][y1] > max(e,d)){
                        effort[x1][y1] = max(e,d);
                        q.push({effort[x1][y1],{x1,y1}});
                    }
                }
            }
        }

        return effort[n - 1][m - 1];
    }
};