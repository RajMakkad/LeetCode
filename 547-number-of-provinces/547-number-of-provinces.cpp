class Solution{
    int parent[201], size[201];
    void initialize(int n){
        for(int i = 1;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findParent(parent[x]);
    }

    void connect(int u,int v){
        u = findParent(u);
        v = findParent(v);

        if(u != v){
            if(size[u] > size[v]){
                parent[v] = u;
                size[u] += size[v];
            }
            else{
                parent[u] = v;
                size[v] += size[u];
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        initialize(n);

        for(int r = 0;r<n;r++){
            for(int c = r + 1;c<n;c++){
                if(isConnected[r][c] == 1){
                    connect(r + 1,c + 1);
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(parent[i] == i) ans++;
        }

        return ans;
    }
};