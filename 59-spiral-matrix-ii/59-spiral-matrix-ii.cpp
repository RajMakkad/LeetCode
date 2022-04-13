class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n));
        int cnt = 1;
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n-1;

        while(right>=left and down>=up){
            for(int i = left;i<=right;i++) mat[up][i] = cnt++;
            for(int i = up + 1;i<=down;i++) mat[i][right] = cnt++;
            for(int i = right - 1;i>=left;i--) mat[down][i] = cnt++;
            for(int i = down - 1;i>up;i--) mat[i][left] = cnt++;
            up++; left++; down--; right--;
        }

        return mat;
    }
};