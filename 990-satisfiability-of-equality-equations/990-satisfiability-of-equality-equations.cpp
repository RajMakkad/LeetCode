class Solution{
    int parent[26], size[26];
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
public:
    bool equationsPossible(vector<string>& eq){
        initialize(26);
        int n = eq.size();

        for(int i = 0;i<n;i++){
            string s = eq[i].substr(1,2);
            if(s == "!=") continue;

            char a = eq[i][0];
            char b = eq[i][3];
            connect(a - 'a',b - 'a');
        }

        for(int i = 0;i<n;i++){
            string s = eq[i].substr(1,2);
            if(s == "==") continue;

            char a = eq[i][0];
            char b = eq[i][3];
            if(findparent(a - 'a') == findparent(b - 'a')) return false;
        }

        return true;
    }
};