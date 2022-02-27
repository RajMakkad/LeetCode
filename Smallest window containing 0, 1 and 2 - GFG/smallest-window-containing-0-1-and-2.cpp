// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s){
        int n = s.length();
        int z = -1;
        int o = -1;
        int t = -1;
        int ans = n + 1;
        
        for(int i = 0;i<n;i++){
            if(s[i] == '0') z = i;
            else if(s[i] == '1') o = i;
            else t = i;
            
            if(z != -1 and o != -1 and t != -1){
                ans = min(ans,max({z,o,t}) - min({z,o,t}) + 1);
            }
        }
        
        return ans == n + 1 ? -1 : ans;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}  // } Driver Code Ends