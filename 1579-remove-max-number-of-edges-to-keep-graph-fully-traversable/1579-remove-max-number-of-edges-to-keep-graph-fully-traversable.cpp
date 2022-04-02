class Solution {
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[0] > b[0];
    }

    int findparent(int x,vector<int> &parent){
        if(parent[x] == x) return x;
        return parent[x] = findparent(parent[x],parent);
    }

    void connect(int u,int v,vector<int> &parent,vector<int> &size){
        u = findparent(u,parent);
        v = findparent(v,parent);

        if(size[u] > size[v]){
            size[u] += size[v];
            parent[v] = u;
        }
        else{
            size[v] += size[u];
            parent[u] = v;
        }
    }

    bool disconnected(vector<int> &p){
        int cnt = 0;
        for(int i = 1;i<p.size();i++){
            if(findparent(i,p) == i) cnt++;
        }

        return 1 < cnt;
    }

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& e) {
        sort(e.begin(),e.end(),comp);
        vector<int> parent1(n + 1), parent2(n + 1), size1(n + 1), size2(n + 1);

        for(int i = 1;i<=n;i++){
            parent1[i] = parent2[i] = i;
            size1[i] = size2[i] = 1;
        }

        int u, v;
        int ans = 0;
        
        for(auto i:e){
            if(i[0] == 3){
                u = findparent(i[1],parent1); 
                v = findparent(i[2],parent1);
                if(u != v) connect(u,v,parent1,size1);

                u = findparent(i[1],parent2); 
                v = findparent(i[2],parent2);
                if(u != v){
                    connect(u,v,parent2,size2);
                    ans++;
                }
            }
            else if(i[0] == 1){
                u = findparent(i[1],parent1); 
                v = findparent(i[2],parent1);
                if(u != v){
                    connect(u,v,parent1,size1);
                    ans++;
                }
            }
            else{
                u = findparent(i[1],parent2); 
                v = findparent(i[2],parent2);
                if(u != v){
                    connect(u,v,parent2,size2);
                    ans++;
                }
            }
        }

        ans = e.size() - ans;
        if(disconnected(parent1) || disconnected(parent2)) ans = -1;
        return ans;
    }
};