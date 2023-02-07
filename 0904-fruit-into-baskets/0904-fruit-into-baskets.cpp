class Solution {
public:
    int totalFruit(vector<int>& f) {
        map<int, int> mp;
        int ans = 0;
        int s = 0;
        
        for(int e = 0;e < f.size();e++){
            mp[f[e]]++;
            
            while(mp.size() > 2){
                mp[f[s]]--;
                if(mp[f[s]] == 0)
                    mp.erase(f[s]);
                
                s++;
            }
            
            ans = max(ans, e - s + 1);
        }
        
        return ans;
    }
};