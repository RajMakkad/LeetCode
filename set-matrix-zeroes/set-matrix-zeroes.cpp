class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int c = 0;
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(mat[i][j] == 0){
                    if(j == 0) c = 1;
                    else mat[i][0] = mat[0][j] = 0;
                }
            }
        }
        
        for(int i = n - 1;i>=0;i--){
            for(int j = m - 1;j>=0;j--){
                if(j == 0){
                    if(c) mat[i][j] = 0;
                }
                else if(mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            }
        }
    }
};