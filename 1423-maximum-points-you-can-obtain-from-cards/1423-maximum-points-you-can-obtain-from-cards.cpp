class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> s(n + 1, 0);
        
        for(int i = n - 1;i >= 0;i--){
            s[i] = s[i + 1] + cardPoints[i];
        }
        
        int ans = s[n - k];
        int sum = 0;
        
        for(int i = 0;i < min(n, k);i++){
            sum += cardPoints[i];
            ans = max(ans, sum + s[n - (k - i - 1)]);
        }
        
        return ans;
    }
};