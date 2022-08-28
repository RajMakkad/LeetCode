#define ss second
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int n = mat.size();
        int m = mat[0].size();
        
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                mp[r - c].push_back(mat[r][c]);
            }
        }
        
        for(auto &i:mp){
            sort(i.ss.begin(), i.ss.end());
            reverse(i.ss.begin(), i.ss.end());
        }
        
        for(int r = 0;r < n;r++){
            for(int c = 0;c < m;c++){
                mat[r][c] = mp[r - c].back();
                mp[r - c].pop_back();
            }
        }
        
        return mat;
    }
};