// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
    void solve(int &x, int &y, int &n, string &s){
        while(x >= 0 and y < n){
            if(s[x] == s[y]) x--, y++;
            else return ;
        }
    }
public:
    string longestPalindrome(string s){
        int n = s.length();
        int len = 0, idx = 0;
        
        for(int i = 0;i < n;i++){
            int x = i, y = i;
            solve(x, y, n, s);
            
            int l = y - x - 1;
            if(l > len) len = l, idx = x + 1;
            
            x = i, y = i + 1;
            solve(x, y, n, s);
            
            l = y - x - 1;
            if(l > len) len = l, idx = x + 1;
        }
        
        return s.substr(idx, len);
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends