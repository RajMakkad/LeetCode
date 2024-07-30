class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int a = 0, b = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a')
                a++;
            else 
                b++;
        }
        int deletions = min(a, b);
        b = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'b')
                b++;
            else
                a--;
            deletions = min(deletions, a + b);
        }
        return deletions;
    }
};