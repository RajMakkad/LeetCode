class SummaryRanges {
    int N = 1e4 + 10;
    vector<int> parent, rank;
    set<int> s;
    
    int findP(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = findP(parent[x]);
    }
    
    void connect(int u, int v){
        u = findP(u);
        v = findP(v);
        
        parent[v] = u;
        rank[u] += rank[v];
    }
public:
    SummaryRanges() {
        parent.resize(N);
        for(int i = 0;i < N;i++)
            parent[i] = -1;
        
        rank.resize(N);
        s.clear();
    }
    
    void addNum(int val) {
        if(parent[val] != -1) 
            return ;
        
        parent[val] = val;
        rank[val] = 1;
        bool left, right;
        
        left = right = false;
        
        if(parent[val + 1] != -1){
            connect(val, val + 1);
            right = true;
        }
        
        if(val > 0 and parent[val - 1] != -1){
            connect(val - 1, val);
            left = true;
        }
        
        if(left and right){
            s.erase(val + 1);
        }
        else if(right){
            s.erase(val + 1);
            s.insert(val);
        }
        else if(!left){
            s.insert(val);
        } 
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto &i: s){
            ans.push_back({i, i + rank[i] - 1});
        }
        
        return ans;
    }
};