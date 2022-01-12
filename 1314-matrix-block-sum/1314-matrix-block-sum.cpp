class Solution {
    int include(int &r,int &c,vector<vector<int>>& mat, int &k){
        int n = mat.size();
        int m = mat[0].size();
        
        int sum = mat[min(r + k,n - 1)][min(c + k,m - 1)];
        int sub = 0;
        if(c > k) sum = sum - mat[min(r + k,n - 1)][c - k - 1];
        if(r > k) sum = sum - mat[r - k - 1][min(c + k,m - 1)];
        
        if(r > k and c > k) sum += mat[max(r - k - 1,0)][c - k - 1];
        
        return sum;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int r = 0;r<n;r++){
            for(int c = 1;c<m;c++){
                mat[r][c] += mat[r][c - 1];
            }
        }
        
        for(int r = 1;r<n;r++){
            for(int c = 0;c<m;c++){
                mat[r][c] += mat[r - 1][c];
            }
                
        }
        
        vector<vector<int>> ans(n,vector<int>(m));
        
        for(int r = 0;r<n;r++){
            for(int c = 0;c<m;c++){
                ans[r][c] = include(r,c,mat,k);
            }
        }
        
        return ans;
    }
};