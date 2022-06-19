class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size(), m = matrix[0].size();
        int left = 0, right = m - 1, up = 0, down = n - 1;
        
        while(right >= left and down >= up){
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[up][i]);
            }
            
            up++;
            
            for(int i = up; i <= down; i++){
                ans.push_back(matrix[i][right]);
            }
            
            right--;
            
            for(int i = right; i >= left and down >= up; i--){
                ans.push_back(matrix[down][i]);
            }
            
            down--;
            
            for(int i = down; i >= up and right >= left; i--){
                ans.push_back(matrix[i][left]);
            }
            
            left++;
        }
        
        return ans;
    }
};