#define mod 1000000007
class Solution {
    int dp[4][3][5001];
    int dx[8] = {-1,-2,-2,-1,1,2,2,1};
    int dy[8] = {-2,-1,1,2,2,1,-1,-2};

    bool isValid(int x,int y){
        if(x >= 0 and y >= 0 and x < 4 and y < 3){
            if((x == 3 and y == 0) || (x == 3 and y == 2)) return false;
            return true;
        }

        return false;
    }
    
    int memoization(int x,int y,int n){
        if(n == 1) return 1;
        if(dp[x][y][n] != -1) return dp[x][y][n];

        int sum = 0;
        for(int i = 0;i<8;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(isValid(x1,y1)){
                sum = (sum + memoization(x1,y1,n - 1)%mod)%mod;
            }
        }

        return dp[x][y][n] = sum;
    }
public:
    int knightDialer(int n) {
        memset(dp,-1,sizeof(dp));

        int ans = 0;
        for(int r = 0;r<4;r++){
            for(int c = 0;c<3;c++){
                if((r == 3 and c == 0) || (r == 3 and c == 2)) continue;
                int cnt = memoization(r,c,n);
                ans = (ans + cnt)%mod;
            }
        }

        return ans;
    }
};