class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans = 1;
        vector<int> d(n + 1, 0);
        
        for(auto &i: trust){
            d[i[1]]++;
            d[i[0]]--;
            
            if(d[i[1]] == n - 1) ans = i[1];
        }
        
        if(d[ans] != n - 1) ans = -1;
        return ans;
    }
};