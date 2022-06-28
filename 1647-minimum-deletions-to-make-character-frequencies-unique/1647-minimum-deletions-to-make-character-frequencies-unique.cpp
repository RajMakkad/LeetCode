class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> mp(n + 1, 0);
        sort(s.begin(), s.end());
        
        int cnt = 1;
        
        for(int i = 1;i< n;i++){
            if(s[i] == s[i - 1]) cnt++;
            else {
                mp[cnt]++;
                cnt = 1;
            }
        }
        
        mp[cnt]++;
        
        int ans = 0;
        
        for(int i = n;i > 0;i--){
            int x = mp[i];
            if(x > 1){
                ans += mp[i] - 1;
                mp[i - 1] += mp[i] - 1;
            }
        }
        
        return ans;
    }
};