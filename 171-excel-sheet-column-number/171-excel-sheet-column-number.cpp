class Solution {
public:
    int titleToNumber(string columnTitle){
        int n = columnTitle.length();
        int ans = 0;
        long long cnt = 1;
        
        for(int i = n - 1;i>=0;i--){
            ans += (columnTitle[i] - 'A' + 1)*cnt;
            cnt = 26*cnt;
        }
        return ans;
    }
};