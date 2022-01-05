class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        int ans = 0;
        int lhs = 0;

        for(int i = 1;i<n;i++){
            ans = max(ans,values[i] + values[lhs] + lhs - i);
            if(values[i] > values[lhs] + (lhs - i)) lhs = i;
        }

        return ans;
    }
};