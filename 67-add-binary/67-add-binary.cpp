class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() - 1;
        int m = b.length() - 1;
        int carry = 0;
        string c = "";
        
        while(n>=0 || m>=0 || carry){
            char ch = '0' + carry;
            if(n>=0) ch += (a[n--] - '0');
            if(m>=0) ch += (b[m--] - '0');
            
            carry = 0;
            if(ch == '0') c += '0';
            if(ch == '1') c += '1';
            if(ch == '2'){
                c += '0';
                carry = 1;
            }
            if(ch == '3'){
                c += '1';
                carry = 1;
            }
        }
        
        reverse(c.begin(),c.end());
        return c;
    }
};