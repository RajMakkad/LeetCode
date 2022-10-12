class Solution {
public:
    int largestVariance(string s) {
        int n = s.length();
        int ans = 0;
        
        for(char i = 'a';i <= 'z';i++){
            for(char j = 'a';j <= 'z';j++){
                if(i == j) continue;
                
                int sum = 0, subAns = 0;
                
                bool present = false;
                bool init1 = false, init2 = false;
                
                for(int k = 0;k < n;k++){
                    int cnt = 0;
                    if(s[k] == i) cnt = 1;
                    if(s[k] == j) {
                        present = true;
                        init1 = true;
                        cnt = -1;
                    }
                    
                    sum += cnt;
                    if(cnt > sum){
                        sum = cnt;
                        init1 = false;
                    }
                    
                    if(sum > subAns){
                        subAns = sum;
                        init2 = init1;
                    }
                    else if(sum == subAns and init1) init2 = true;
                }
                
                if(subAns > ans){
                    if(init2) ans = subAns;
                    else if(present) ans = subAns - 1;
                }
            }
        }
        
        return ans;
    }
};