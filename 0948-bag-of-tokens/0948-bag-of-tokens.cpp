class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int s = 0;
        int e = n - 1;
        sort(tokens.begin(), tokens.end());
        int ans = 0;
        int curr = 0;
        
        while(e >= s){
            if(power >= tokens[s]){
                power -= tokens[s++];
                curr++;
            } else if(curr > 0){
                curr--;
                power += tokens[e--];
            }
            else 
                break;
            ans = max(ans, curr);
        }
        return ans;
    }
};