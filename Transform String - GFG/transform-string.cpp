// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string a, string b){
        int n = a.length(), m = b.length();
        vector<int> cnt(123,0);
    
        for(int i = 0;i<n;i++) cnt[a[i] - 'A']++;
        for(int i = 0;i<m;i++) cnt[b[i] - 'A']--;
        for(int i = 0;i<123;i++){
            if(cnt[i] != 0) return -1;
        }
    
        n--, m--;
        int ans = 0;
    
        while(n >= 0 and m >= 0){
            if(a[n] == b[m]){
                n--, m--;
            }
            else ans++, n--;
        }
    
        return ans == m + 1 ? ans : -1;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends