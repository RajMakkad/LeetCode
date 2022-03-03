// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
public:
    long long countStrings(string s){
        long n = s.length();
        long long ans = 0;
        bool more = false;
        
        vector<long long> cnt(26,0);
        for(int i = 0;i<n;i++) cnt[s[i] - 'a']++;
        
        ans += n*(n - 1)/2LL;
        
        for(int i = 0;i<26;i++){
            if(cnt[i] > 1) more = true;
            ans = ans - cnt[i]*(cnt[i] - 1)/2LL;
        }
        
        if(more) ans += 1LL;
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution ob;
        long long ans = ob.countStrings(S);
        cout<<ans<<endl;
    }
    return 0;
}   // } Driver Code Ends