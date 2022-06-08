class Solution {
    int parent[100001], size[100001];
    void initialize(){
        for(int i = 1;i<= 100000;i++){
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
    bool gcdSort(vector<int>& nums){
        int n = nums.size();
        initialize();

        for(int i = 0;i<n;i++){
            int x = nums[i];
            vector<int> g = {nums[i]};

            for(int p = 2;p*p<=x;p++){
                if(x % p == 0){
                    g.push_back(p);
                    while(x % p == 0) x /= p;
                }
            }

            if(x != 1) g.push_back(x);

            for(int p = 0;p<g.size();p++){
                connect(g[0], g[p]);
            } 
        }

        vector<int> sub = nums;
        sort(sub.begin(),sub.end());

        for(int i = 0;i<n;i++){
            if(nums[i] != sub[i]){
                int u = findParent(nums[i]);
                int v = findParent(sub[i]);

                if(u != v) return false;
            }
        }

        return true;
    }
};