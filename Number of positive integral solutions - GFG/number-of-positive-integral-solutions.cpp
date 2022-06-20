// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    long posIntSol(string s){
        int n = s.length();
        int var = 0;
        int k = 0;
    
        for(int i = 0;i<n;i++){
            if(s[i] >= 'a' and 'z' >= s[i]) var++;
            else if(isdigit(s[i])) k = k * 10 + (s[i] - '0');
        }
    
        var--, k--;
        long long num = 1, deno = 1;
    
        for(long i = 0;i<var;i++){
            num *= (k - i);
        }
    
        for(long i = 1; i <= var;i++){
            deno *= i;
        }
    
        long ans = num / deno;
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends