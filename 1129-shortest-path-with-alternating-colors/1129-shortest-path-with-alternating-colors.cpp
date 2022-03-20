class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> red[n],blue[n];

        for(auto &i:redEdges) red[i[0]].push_back(i[1]);
        for(auto &i:blueEdges) blue[i[0]].push_back(i[1]);

        queue<pair<int,char>> q;
        vector<int> d_r(n,1e9),d_b(n,1e9);
        d_r[0] = d_b[0] = 0;
        q.push({0,'R'});
        q.push({0,'B'});

        while(!q.empty()){
            int node = q.front().first;
            int colour = q.front().second;
            q.pop();

            if(colour == 'R'){
                for(auto &i:blue[node]){
                    if(d_b[i] > d_r[node] + 1){
                        d_b[i] = d_r[node] + 1;
                        q.push({i,'B'});
                    }
                }
            }
            else if(colour == 'B'){
                for(auto &i:red[node]){
                    if(d_r[i] > d_b[node] + 1){
                        d_r[i] = d_b[node] + 1;
                        q.push({i,'R'});
                    }
                }
            }
        }

        vector<int> dist(n);
        for(int i = 0;i<n;i++){
            dist[i] = min(d_r[i],d_b[i]);
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
};