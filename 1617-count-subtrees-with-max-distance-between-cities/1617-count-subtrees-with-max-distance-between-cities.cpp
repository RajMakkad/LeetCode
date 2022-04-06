int maxDistance(int n,int state,vector<vector<int>> dist){
    int city = 0, edge = 0, d = 0;

    for(int i = 0;i<n;i++){
        int p = ((state>>i)&1);
        if(p == 0) continue;

        city++;
        for(int j = i + 1;j<n;j++){
            p = ((state>>j)&1);
            if(p == 0) continue;

            edge += (dist[i][j] == 1);
            d = max(d,dist[i][j]);
        }
    }

    if(edge + 1 != city) return 0;
    return d;
}

class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        vector<int> sub(n - 1,0);

        for(auto &i:edges){
            dist[i[0] - 1][i[1] - 1] = dist[i[1] - 1][i[0] - 1] = 1;
        }

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    dist[j][i] = dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }

        for(int i = 0;i<(1<<n);i++){
            int d = maxDistance(n,i,dist);
            if(d > 0) sub[d - 1]++;
        }

        return sub;
    }
};
