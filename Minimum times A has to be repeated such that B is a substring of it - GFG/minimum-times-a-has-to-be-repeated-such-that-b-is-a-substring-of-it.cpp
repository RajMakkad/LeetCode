//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        int n = a.length();
        int m = b.length();
        
        string sub = a;
        int ans = 1;
        
        while(m > sub.length()){
            sub += a;
            ans++;
        }
        
        for(int i = 0;i + m <= sub.length();i++){
            if(sub.substr(i, m) == b)
                return ans;
        }
        
        sub += a;
        ans++;
        
        for(int i = 0;i + m <= sub.length();i++){
            if(sub.substr(i, m) == b)
                return ans;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ",&t);
    while (t--) {
        string A,B;
        getline(cin,A);
        getline(cin,B);

        Solution ob;
        cout << ob.minRepeats(A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends