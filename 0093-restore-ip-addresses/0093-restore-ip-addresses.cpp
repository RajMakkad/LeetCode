class Solution {
    int cnt= 0;
    void solve(int idx, int &n, string &s, string sub, vector<string> &ans){
        if(idx >= n){
            if(cnt == 4)
                ans.push_back(sub);
        }
        else {
            int sum = 0;
            string sub1 = "";
            bool z = false;
            cnt++;
            
            for(int i = idx;i < n;i++){
                sum = sum * 10 + (s[i] - '0');
                sub1 += s[i];
                
                if(i == idx and s[i] == '0') z = true;
                    
                if((z and i != idx) || sum > 255 || cnt > 4)
                    break;
                
                if(i != n - 1) sub1 += '.';
                
                solve(i + 1, n, s, sub + sub1, ans);
                
                if(i != n - 1) sub1.pop_back();
            }
            
            cnt--;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n = s.length();
        cnt = 0;
        
        
        solve(0, n, s, "", ans);
        
        return ans;
    }
};