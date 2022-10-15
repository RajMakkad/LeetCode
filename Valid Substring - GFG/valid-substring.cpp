//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    int findMaxLen(string s) {
        int n = s.length(), ans = 0;
        
        int ls = 0, rs = 0;
        
        for(int i = 0;i < n;i++){
            if(s[i] == '(') ls++;
            else rs++;
            
            if(ls == rs) ans = max(ans, ls + rs);
            if(rs > ls) ls = rs = 0;
        }
        
        ls = rs = 0;
        for(int i = n - 1;i >= 0;i--){
            if(s[i] == '(') ls++;
            else rs++;
            
            if(ls == rs) ans = max(ans, ls + rs);
            if(rs < ls) ls = rs = 0;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends