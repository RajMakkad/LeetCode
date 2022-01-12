class NumMatrix {
    vector<vector<int>> mat;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        for(int r = 0;r<n;r++){
            for(int c = 1;c<m;c++) matrix[r][c] += matrix[r][c - 1];
        }
        
        for(int r = 1;r<n;r++){
            for(int c = 0;c<m;c++) matrix[r][c] += matrix[r - 1][c];
        }
        
        mat = matrix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = mat[row2][col2];
        if(row1 > 0) ans = ans - mat[row1 - 1][col2];
        if(col1 > 0) ans = ans - mat[row2][col1 - 1];
        if(col1 > 0 and row1 > 0) ans += mat[row1 - 1][col1 - 1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */