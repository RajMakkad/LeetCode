// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            s += '.';
            int n = s.length();
            
            int x = 0;
            int count = 0;
            while(x < n){
                int num = 0;
                int y = x, leadingZero = 0;
                while(s[y] != '.'){
                    if(num == 0 and s[y] == '0') leadingZero++;
                    if(!isdigit(s[y])) return false;
                    
                    num = num * 10 + (s[y++] - '0');
                }
                if(num > 255) return false;
                if(num == 0 and leadingZero != 1) return false;
                if(num != 0 and leadingZero > 0) return false;
                
                count++;
                x = y + 1;
            }
            
            return count == 4;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends