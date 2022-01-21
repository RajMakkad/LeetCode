// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string str){
        int n = str.length();
        vector<vector<int>> p(n + 1,vector<int>(n + 1,0));

        for(int g = 0;g<n;g++){
            for(int s = 0;s + g<n;s++){
                int e = s + g;

                if(g == 0) p[s][e] = 1;
                else if(g == 1 and str[s] == str[e]) p[s][e] = 1;
                else if(p[s + 1][e - 1] and str[s] == str[e]) p[s][e] = 1;
            }
        }

        

        unordered_set<string> count;
        for(int s = 0;s<n;s++){
            string sub = "";
            for(int i = s;i<n;i++){
                sub += str[i];
                if(p[s][i]) count.insert(sub);
            }
        }

        return (int)count.size();
    }
};  

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends