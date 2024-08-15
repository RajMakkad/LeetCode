class TreeAncestor {
    vector<vector<int>> up;
    int log = 0;
public:
    TreeAncestor(int n, vector<int>& parent) {
        while((1 << log) <= n)
            log++;
        up.resize(n, vector<int>(log, -1));
        for(int l = 0; l < log; l++){
            for(int i = 0; i < n; i++){
                if(l == 0)
                    up[i][l] = parent[i];
                else {
                    int l_1 = up[i][l - 1];
                    if(l_1 != -1)
                        up[i][l] = up[l_1][l - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int l = 0; l < log and node != -1; l++)
            if((k & (1 << l)))
                node = up[node][l];
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */