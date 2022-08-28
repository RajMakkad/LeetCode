class Solution {
    int solve(vector<int> &v, int n, int k){
        int ans = INT_MIN, sum = 0;
        set<int> s;
        s.insert(0);
        
        for(int i = 0;i < n;i++){
            sum += v[i];
            
            int need = sum - k;
            auto u = s.lower_bound(need);
            if(u != s.end()) ans = max(ans, sum - *u);
            
            s.insert(sum);
        }
        
        return ans;
    }
public:
    int maxSumSubmatrix(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int r = 0;r < n;r++){
            for(int c = 1;c < m;c++){
                mat[r][c] += mat[r][c - 1];
            }
        }
        
        int ans = INT_MIN;
        
        for(int c1 = 0;c1 < m;c1++){
            for(int c2 = c1;c2 < m;c2++){
                vector<int> v(n);
                
                for(int r = 0;r < n;r++){
                    v[r] = mat[r][c2];
                    if(c1 > 0) v[r] = v[r] - mat[r][c1 - 1];
                }
                
                ans = max(ans, solve(v, n, k));
            }
        }
        
        return ans;
    }
};