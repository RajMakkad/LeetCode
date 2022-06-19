class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sumPoints = 0, sumInterval = 0;
        int s = 0;
        int min_ = 1e9;
        
        for(int i = 0;i < n;i++){
            sumPoints += cardPoints[i];
        }
        
        k = n - k;
        for(int e = 0;e < n;e++){
            sumInterval += cardPoints[e];
            if(e - s + 1 > k) sumInterval -= cardPoints[s++];
            
            if(e - s + 1 == k) min_ = min(min_, sumInterval);
        }
        
        int ans = sumPoints - min_;
        return ans;
    }
};