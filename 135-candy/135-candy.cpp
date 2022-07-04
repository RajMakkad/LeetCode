class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> a(n, vector<int>(2));
        
        for(int i = 0;i < n;i++){
            a[i][0] = ratings[i];
            a[i][1] = i;
        }
        
        sort(a.begin(), a.end());
        
        vector<int> candy(n);
        int ans = 0;
        
        for(int i = 0;i < n;i++){
            int x = 1;
            int idx = a[i][1];
            if(idx > 0 and ratings[idx - 1] < ratings[idx]) x = max(x, candy[idx - 1] + 1);
            if(idx + 1 < n and ratings[idx + 1] < ratings[idx]) x = max(x, candy[idx + 1] + 1);
            
            ans += x;
            candy[idx] = x;
        }
        
        return ans;
    }
};