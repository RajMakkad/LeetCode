class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> v(26, 0);
        
        for(auto w:words2){
            vector<int> cnt(26, 0);
            for(int i = 0;i < w.size();i++){
                int x = w[i] - 'a';
                cnt[x]++;
            }
            
            for(int i = 0;i < 26;i++) v[i] = max(v[i], cnt[i]);
        }
        
        vector<string> ans;
        
        for(auto w:words1){
            vector<int> cnt(26, 0);
            for(int i = 0;i < w.size();i++){
                int x = w[i] - 'a';
                cnt[x]++;
            }
            
            bool pass = true;
            for(int i = 0;i < 26;i++){
                if(cnt[i] < v[i]){
                    pass = false;
                    break;
                }
            }
            
            if(pass) ans.push_back(w);
        }
        
        return ans;
    }
};