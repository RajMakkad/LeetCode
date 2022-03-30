class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();
        int s = 0;
        int e = n*m - 1;
        int mid = s + (e - s)/2;
        
        while(e >= s){
            mid = s + (e - s)/2;
            int v = mat[mid/m][mid%m];
            
            if(target == v) return true;
            else if(target > v) s = mid + 1;
            else e = mid - 1;
        }
        
        return false;
    }
};