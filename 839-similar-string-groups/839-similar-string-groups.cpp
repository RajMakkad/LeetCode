class Solution{
    int parent[300], size[300];
    void initialize(int n){
        for(int i = 0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findparent(int x){
        if(x == parent[x]) return x;
        return parent[x] = findparent(parent[x]);
    }

    void connect(int u,int v){
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

    bool isSimilar(string &a,string &b){
        int n = a.length();
        int cnt = 0;
        for(int i = 0;i<n;i++){
            if(a[i] != b[i]) cnt++;
        }

        return cnt == 0 || cnt == 2;
    }

public:
    int numSimilarGroups(vector<string>& s){
        int n = s.size();
        initialize(n);

        for(int i = 0;i<n;i++){
            for(int j = i + 1;j<n;j++){
                if(isSimilar(s[i],s[j])){
                    connect(i,j);
                }
            }
        }

        int ans = 0;
        for(int i = 0;i<n;i++){
            if(parent[i] == i) ans++;
        }

        return ans;
    }
};