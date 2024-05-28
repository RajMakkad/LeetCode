class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> arr(n, 0);
        for(int i = 0;i < n;i++){
            arr[i] = abs(s[i] - t[i]);
        }
        
        int i = 0, j = 0, sum = 0, ans = 0;
        while(j < n){
            sum += arr[j++];
            while(sum > maxCost)
                sum = sum - arr[i++];
            ans = max(ans, j - i);
        }
        
        return ans;
    }
};