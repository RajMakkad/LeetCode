class Solution {
    int solve(int d1, int d2, int n, vector<int> digit[]){
        int ans = n;
        for(auto i: digit[d1]){
            for(auto j: digit[d2]){
                if(j > i)
                    ans = min(ans, n - i - 2);
            }
        }
        return ans;
    }
public:
    int minimumOperations(string num) {
        vector<int> digit[10];
        int n = num.length();
        int ans = n;
        for(int i = 0;i < num.length(); i++){
            digit[num[i] - '0'].push_back(i);
        }
        int options[4][2] = {
            {0, 0},
            {2, 5},
            {5, 0},
            {7, 5}
        };   
        for(auto op: options){
            ans = min(ans, solve(op[0], op[1], n, digit));
        }
        if(digit[0].size() > 0)
            ans = min(ans, n - 1);
        return ans;
    }
};