class Solution {
    bool solve(int idx, int x, int y, string &s, vector<vector<char>> &b){
        if(idx >= s.length()) return true;
        
        b[x][y] = '-';
        
        int n = b.size();
        int m = b[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0;i < 4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];

            if(x1 >= 0 and y1 >= 0 and x1 < n and y1 < m and b[x1][y1] == s[idx]){
                if(solve(idx + 1, x1, y1, s, b)) return true;
            }
        }
        
        b[x][y] = s[idx - 1];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                if(word[0] == board[r][c] and solve(1, r, c, word, board)) return true;
            }
        }

        return false;
    }
};