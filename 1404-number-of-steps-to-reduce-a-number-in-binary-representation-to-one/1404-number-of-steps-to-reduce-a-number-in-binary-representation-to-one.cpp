class Solution {
public:
    int numSteps(string s) {
        int ans = 0, carry = 0;
        for(int i = s.length() - 1; i > 0; i--){
            ans++;
            if(s[i] - '0' + carry == 1){
                carry = 1;
                ans++;
            }
        }
        return ans + carry;
    }
};