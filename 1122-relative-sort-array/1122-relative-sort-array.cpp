class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> dp(1000 + 1, -1);
        int n = arr2.size();
        
        for(int i = 0;i < n; i++)
            dp[arr2[i]] = i;
        
        for(int i = 0;i < arr1.size(); i++)
            if(dp[arr1[i]] == -1)
                dp[arr1[i]] = n + arr1[i];
        
        sort(arr1.begin(), arr1.end(), [&](const int a, const int b){
            return dp[a] < dp[b];
        });
        return arr1;
    }
};