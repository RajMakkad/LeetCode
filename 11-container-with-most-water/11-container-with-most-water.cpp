class Solution {
public:
    int maxArea(vector<int>& h) {
        int x = 0;
        int y = h.size() - 1;
        int ans = 0;
        
        while(y > x){
            ans = max(ans, min(h[x], h[y]) * (y - x));
            if(h[x] > h[y]) y--;
            else x++;
        }
        
        return ans;
    }
};