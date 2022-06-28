class Solution {
public:
    int minDeletions(string s) {
        unordered_map<int, int> mp;
        sort(s.begin(), s.end());
        
        int cnt = 1;
        int max_ = 0;
        for(int i = 1;i< s.length();i++){
            if(s[i] == s[i - 1]) cnt++;
            else {
                mp[cnt]++;
                cnt = 1;
            }
            
            max_ = max(max_, cnt);
        }
        
        mp[cnt]++;
        
        int ans = 0;
        
        for(int i = max_;i > 0;i--){
            int x = mp[i];
            if(x > 1){
                ans += mp[i] - 1;
                mp[i - 1] += mp[i] - 1;
            }
        }
        
        return ans;
    }
};