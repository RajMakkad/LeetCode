#define N 10000
class Solution{
    int parent[N + 1], size[N + 1];
    map<int,vector<int>> mp;

    void initialize(int n){     // O(N)
        for(int i = 1;i<=n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    void getdivisors(int n,int bound){    // O(N*sqrt(N))
        for(int i = bound;i<=n;i++){
            for(int d = 1;d*d <= i;d++){
                if(i % d == 0){
                    if(d > bound) mp[d].push_back(i);
                    if(d*d != i and i/d > bound) mp[i/d].push_back(i);
                }
            }
        }
    }
    int findparent(int x){   // O(log(N))
        if(parent[x] == x) return x;
        return parent[x] = findparent(parent[x]);
    }
    void connect(int u,int v){    // O(log(N))
        u = findparent(u);
        v = findparent(v);

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
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        initialize(n);
        getdivisors(n,threshold);

        for(auto &p:mp){
            vector<int> sub = p.second;
            for(int i = 1;i<sub.size();i++){
                connect(sub[0],sub[i]);
            }
        }

        int m = queries.size();
        vector<bool> ans(m);
        for(int i = 0;i<m;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            u = findparent(u);
            v = findparent(v);

            ans[i] = (u == v);
        }

        return ans;
    }
};