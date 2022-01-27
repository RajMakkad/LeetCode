class Solution{
    bool is_valid(int &row,int &col,vector<string> &s){
        int n = s.size();
        for(int i = col;i>=0;i--){
            if(s[row][i] == 'Q') return false;
        }

        for(int i = row,j = col; i>=0 and j>=0; i-- , j--){
            if(s[i][j] == 'Q') return false;
        }

        for(int i = row,j = col; i<n and j>=0; i++ , j--){
            if(s[i][j] == 'Q') return false;
        }

        return true;
    }

    void position(int &col,vector<string> &s,vector<vector<string>> &g){
        int n = s.size();
        if(col >= n){
            g.push_back(s);
            return ;
        }

        for(int i = 0;i<n;i++){
            if(!is_valid(i,col,s)) continue;

            s[i][col++] = 'Q';

            position(col,s,g);
            
            s[i][--col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> g;
        vector<string> s(n,string(n,'.'));

        int col = 0;
        position(col,s,g);
        return g;
    }
};