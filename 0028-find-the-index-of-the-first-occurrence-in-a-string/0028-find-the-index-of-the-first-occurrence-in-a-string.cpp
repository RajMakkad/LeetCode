#define ll long long int
const ll p = 1e9 + 7;

class Solution {
public:
    int strStr(string hays, string need) {
        int n = hays.size();
        int m = need.size();;
        
        if(m > n)
            return -1;
        
        ll hash = 0;
        ll mul = 1;
        
        vector<ll> seg(m);
        
        for(int i = m - 1;i >= 0;i--){
            mul = (mul * 26LL) % p;
            seg[i] = mul;
            
            hash = (hash + ((need[i] - 'a' + 1) * mul) % p) % p;
        }
        
        ll counter = 0;
        
        for(int i = 0;i < n;i++){
            if(i < m){
                counter = (counter + (hays[i] - 'a' + 1) * seg[i]) % p;
            }
            else {
                counter = (counter - (hays[i - m] - 'a' + 1) * seg[0]) % p;
                counter = (counter + p) % p;
                
                counter = ((counter + (hays[i] - 'a' + 1)) * seg[m - 1]) % p;
            }
            
            if(counter == hash and hays.substr(i - m + 1, m) == need)
                return i - m + 1;
        }
        
        return -1;
    }
};