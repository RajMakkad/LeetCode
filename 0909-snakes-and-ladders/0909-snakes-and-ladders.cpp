#define pi pair<int, int>
#define ff first
#define ss second

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<pi> dest(n * n + 1);
        vector<int> col(n);
        
        iota(col.begin(), col.end(), 0);
        int idx = 1;
        for(int r = n - 1;r >= 0;r--){
            for(auto &c: col){
                dest[idx++] = {r, c};
            }
            
            reverse(col.begin(), col.end());
        }
        
        vector<int> ans(n * n + 1, -1);
        queue<int> q;
        q.push(1);
        
        ans[1] = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            
            for(int i = 1;i <= 6;i++){
                if(x + i > n * n)
                    break;
               
                int next = board[dest[i + x].ff][dest[i + x].ss] == -1 ? i + x: board[dest[i + x].ff][dest[i + x].ss];
                if(ans[next] == -1){
                    ans[next] = ans[x] + 1;
                    q.push(next);
                }
            }
        }
        
        return ans[n * n];
    }
};