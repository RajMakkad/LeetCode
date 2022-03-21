// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minRepeats(string a, string b) {
        int n = a.length();
        int m = b.length();

        string s = "";
        while(b.length() >= s.length()) s += a;
        s += a;

        int l = s.length();
        for(int i = 0;i<l;i++){
            if(s.substr(i,m) == b){
                int ans = (i + m + n - 1)/n;
                return ans;
            }
        }

        return -1;
    }
};


// { Driver Code Starts.

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
}  // } Driver Code Ends