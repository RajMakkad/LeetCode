class Solution {
    bool solve(int r, int c, vector<vector<char>> &board, string &word, int idx){
        if(idx >= word.size())
            return true;
        board[r][c] = '-';
        int n = board.size();
        int m = board[0].size();
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        
        for(int i = 0;i < 4;i++){
            int x = r + dx[i];
            int y = c + dy[i];
            if(x >= 0 and y >= 0 and x < n and y < m and board[x][y] == word[idx])
                if(solve(x, y, board, word, idx + 1))
                    return true;
        }
        board[r][c] = word[idx - 1];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                if(word[0] == board[r][c] and solve(r, c, board, word, 1))
                    return true;
            }
        }
        return false;
    }
};