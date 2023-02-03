class Solution {
    void update(int &count, int &sign, int &numRows){
        if((count == numRows and sign == 1) || (count == 1 and sign == -1)) 
            sign *= -1;
    }
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        
        int n = s.length();
        vector<int> v(n, 0);
        vector<string> sub(numRows + 1, "");
        
        int count = 0;
        int sign = 1;
        
        for(int i = 0;i < n;i++){
            count += sign;
            v[i] = count;
            sub[v[i]] += s[i];
            
            update(count, sign, numRows);
        }
        
        string ans = "";
        
        for(int i = 1;i <= numRows;i++)
            ans += sub[i];
        
        return ans;
    }
};