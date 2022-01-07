class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int max_height = *max_element(h.begin(),h.end());
        int ans = n*max_height;
        int t = 0;

        for(int i = 0;i<n;i++){
            t = max(t,h[i]);
            ans = ans - (max_height - t) - h[i];
        }

        t = 0;
        for(int i = n - 1;i>=0;i--){
            t = max(t,h[i]);
            ans = ans - (max_height - t);
        }

        return ans;
    }
};