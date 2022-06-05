class Solution {
    int ans = 0;
    bool isValid(int row,int col,vector<vector<char>> &a){
        int n = a.size();
        for(int i = col - 1;i>=0;i--){
            if(a[row][i] == 'x') return false;
        }

        int x = row - 1, y = col - 1;
        while(x >= 0 and y >= 0){
            if(a[x][y] == 'x') return false;
            x--, y--;
        }

        x = row + 1, y = col - 1;
        while(x < n and y >= 0){
            if(a[x][y] == 'x') return false;
            x++, y--;
        }

        return true;
    }
    void formation(int col,vector<vector<char>> &a){
        int n = a.size();
        if(col >= n){
            ans ++;
            return ;
        }

        for(int i = 0;i<n;i++){
            if(!isValid(i,col,a)) continue;

            a[i][col] = 'x';
            formation(col + 1,a);
            a[i][col] = '.';
        }
    }
public:
    int totalNQueens(int n) {
        vector<vector<char>> a(n,vector<char>(n,'.'));

        ans = 0;
        formation(0,a);
        return ans;
    }
};