class Solution {
public:
    string removeDuplicateLetters(string s){
        int n = s.length();
        vector<int> pos(26,0),present(26,0);
        
        for(int i = 0;i<n;i++) pos[s[i] - 'a'] = i;
        
        string ans = "";
        for(int i = 0;i<n;i++){
            if(present[s[i] - 'a'] == 1) continue;
            while(ans.size() and ans.back() > s[i] and pos[ans.back() - 'a'] > i){
                present[ans.back() - 'a'] = 0;
                ans.pop_back();
            }
            
            ans += s[i];
            present[s[i] - 'a'] = 1;
        }
        
        return ans;
    }
};