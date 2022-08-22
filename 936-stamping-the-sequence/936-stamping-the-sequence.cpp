class Solution {
    bool isPossible(int idx, string &stamp, string &target){
        int n = stamp.length();
        for(int i = 0;i < n;i++){
            if(stamp[i] != target[i + idx] and target[i + idx] != '?'){
                return false;
            }
        }
        
        for(int i = 0;i < n;i++){
            target[i + idx] = '?';
        }
        
        return true;
    }
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.length(), m = target.length();
        
        vector<int> ans, vis(m, 0);
        
        bool change = true;
        while(change){
            change = false;
            for(int i = 0;i <= m - n;i++){
                if(vis[i] == 0 and isPossible(i, stamp, target)){
                    ans.push_back(i);
                    vis[i] = 1;
                    change = true;
                }
            }
        }
        
        for(int i = 0;i < m;i++){
            if(target[i] != '?'){
                return {};
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};