class Solution {
    bool is_lucky(int r, int c, vector<vector<int>>& matrix){
        int num = matrix[r][c];
        for(int i = 0; i < matrix[0].size(); i++){
            if(matrix[r][i] < num)
                return false;
        }
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][c] > num)
                return false;
        }
        return true;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> res;
        int n = matrix.size();
        int m = matrix[0].size();
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(is_lucky(r, c, matrix))
                    res.push_back(matrix[r][c]);
            }
        }
        return res;
    }
};