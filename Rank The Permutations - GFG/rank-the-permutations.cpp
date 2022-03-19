// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    long long findRank(string str){
        vector<long long> fact(19);
        fact[0] = 1;
        for(int i = 1;i<=18;i++){
            fact[i] = fact[i - 1]*i;
        }

        int n = str.length();
        long long rank = 1;


        for(int i = 0;i<n;i++){
            int count = 0;
            for(int j = i + 1;j<n;j++){
                count += (str[i] > str[j]);
            }
            
            rank += count*fact[n - i - 1];
            
        }

        return rank ;
    }
};

// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends