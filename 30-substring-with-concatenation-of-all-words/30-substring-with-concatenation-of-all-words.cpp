class Solution {
    bool solve(string s, unordered_map<string, int> mp, int n, int l){
        for(int i = 0;i < n;i += l){
            string p = s.substr(i, l);
            if(mp.find(p) != mp.end() and mp[p] > 0){
                mp[p]--;
            }
            else return false;
        }
        
        return true;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.length();
        int l = words[0].size();
        int L = words.size() * l;
        
        unordered_map<string, int> mp;
        for(auto w: words) mp[w]++;
        
        vector<int> ans;
        
        int i = 0;
        while(i + L <= n){
            if(solve(s.substr(i, L), mp, L, l)){
                ans.push_back(i);
            }
            i++;
        }
        
        return ans;
    }
};