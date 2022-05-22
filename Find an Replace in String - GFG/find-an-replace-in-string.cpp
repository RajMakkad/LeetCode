// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string s ,int m, int index[], string sources[], string targets[]) {
        string ans = "";
        int n = s.length(), i = 0, idx = 0;

        while(i < n){
            if(idx < m){
                if(i < index[idx]) ans += s[i++];
                else{
                    int size = sources[idx].size();
                    if(s.substr(i,size) == sources[idx]){
                        ans += targets[idx];
                        i += size;
                    }
                    else ans += s[i++];
                    idx++;
                }
            }
            else ans += s[i++];
        }

        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends