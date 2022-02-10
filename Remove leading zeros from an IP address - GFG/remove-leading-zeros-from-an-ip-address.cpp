// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    string newIPAdd (string s){
        s += '.';
        string ans = "";
        string sub = "";
        char c = '.';

        for(auto &i:s){
            if(i == '.'){
                if(sub.empty()) ans += '0';
                else ans += sub;
                ans += '.';
                sub = "";
            }
            else if(i != '0' || (!sub.empty()))  sub += i;
        }

        ans.pop_back();
        return ans;
    }
};
// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.newIPAdd (s) << endl;
    }
}

  // } Driver Code Ends