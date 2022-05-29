class Solution {
public:
    int maxProduct(vector<string>& w) {
        int n = w.size();
        int ans = 0;
        vector<int> mask(n,0);

        for(int i = 0;i<n;i++){
            for(auto j:w[i]){
                int x = j - 'a';
                mask[i] |= (1<<x);
            }

            for(int j = 0;j<i;j++){
                if((mask[i] & mask[j]) == 0) ans = max(ans,(int)w[i].size() * (int)w[j].size());
            }
        }

        return ans;
    }
};