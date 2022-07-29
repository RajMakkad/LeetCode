class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        int n = p.length();
        vector<int> g[26];
        
        for(int i = 0;i < n;i++){
            int x = p[i] - 'a';
            g[x].push_back(i);
        }
        
        vector<string> ans;
        
        for(auto w : words){
            vector<int> v[26];
            bool pass = true;
            
            for(int i = 0;i < n;i++){
                int x = w[i] - 'a';
                v[x].push_back(i);
            }
            
            for(int i = 0;i < n;i++){
                int x = w[i] - 'a';
                int y = p[i] - 'a';
                
                if(v[x] != g[y]){
                    pass = false;
                    break;
                }
                
                if(!pass) break;
            }
            
            if(pass) ans.push_back(w);
        }
        
        return ans;
    }
};