class Solution {
public:
    vector<int> findArray(vector<int>& p) {
        int n = p.size();
        for(int i = n - 1;i > 0;i--){
            p[i] ^= p[i - 1];
        }
        
        return p;
    }
};