class Solution{
    int parent(int x,vector<int> &p){
        if(x == p[x]) return x;
        return p[x] = parent(p[x],p);
    }
    void connect(int x,int y,vector<int> &p){
        int p_x = parent(x,p);
        int p_y = parent(y,p);

        if(p_x != p_y) p[p_y] = p_x;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();
        vector<int> p(n + 1);

        for(int i = 1;i<=n;i++) p[i] = i;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                    connect(i + 1,j + 1,p);
                }
            }
        }

        int ans = 0;
        for(int i = 1;i<=n;i++){
            if(p[i] == i) ans++;
        }

        return ans;
    }
};