#define ll long long 
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        ll ans = 0;
        unordered_set<string> a[26];
        
        for(auto &i: ideas)
            a[i[0] - 'a'].insert(i.substr(1));
        
        for(int i = 0;i < 26;i++){
            for(int j = i + 1;j < 26;j++){
                int n = a[i].size();
                int m = a[j].size();
                int cnt = 0;
                
                for(auto &c: a[i])
                    if(a[j].count(c)) 
                        cnt++;
                
                ans += (n - cnt) * (m - cnt);
            }
        }
        
        ans = 2 * ans;
        return ans;
    }
};