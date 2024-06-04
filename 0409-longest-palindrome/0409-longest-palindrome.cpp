class Solution {
public:
    int longestPalindrome(string s) {
        int dp[100] = {0};
        for(auto c: s)
            dp[c - 'A']++;
        int odd = 0;
        int sum = 0;
        for(int i = 0; i < 100; i++) {
            sum += dp[i] % 2 ? dp[i] - 1 : dp[i];
            odd |= dp[i] % 2;
        }
        return sum + odd;
    }
};