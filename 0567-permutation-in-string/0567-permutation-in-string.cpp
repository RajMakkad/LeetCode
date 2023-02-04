class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) 
            return false;
        
        vector<int> hash(26, 0);
        vector<int> temp(26, 0);

        for(auto i : s1) 
            hash[(i - 'a')]++;
        
        for(int i = 0;i < m;i++){
            temp[(s2[i] - 'a')]++;
                
            if(i >= n - 1) {
                
                if(temp == hash) 
                    return true;
                
                temp[(s2[i - n + 1] - 'a')]--;
            }
        }

        return false;
    }
};