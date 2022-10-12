//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          vector<int> v(100, 1e4);
          
          for(int i = 0;i < n;i++){
              int ch = x[i] - 'A';
              v[ch] = b[i];
          }
          
          int sum = -1e9;
          int ans = -1e9;
          int s1 = 0, s2 = -1, e2 = -1;
          
         for(int i = 0;i < w.length();i++){
              int ch = w[i] - 'A';
              if(v[ch] == 1e4) v[ch] = w[i];
              
              sum += v[ch];
              
              if(v[ch] > sum){
                  sum = v[ch];
                  s1 = i;
              }
              
              if(sum > ans){
                  ans = sum;
                  s2 = s1;
                  e2 = i;
              }
          }
          
          if(s2 == -1) return "0";
          return w.substr(s2, e2 - s2 + 1);
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends