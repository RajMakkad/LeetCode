#define ll long long int
class Solution {
    bool solve(ll n, string &t){
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        return s == t;
    }
public:
    bool reorderedPowerOf2(int n) {
        string t = to_string(n);
        sort(t.begin(), t.end());
        
        ll x = 1;
        while(x <= 1e10){
            if(solve(x, t)){
                return true;
            }
            
            x = 2LL * x;
        }
        
        return false;
    }
};