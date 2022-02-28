// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution{
    unordered_map<string,int> mp;
    public:
    long long countPairs(int n, int x, vector<int> nums){
        string s = to_string(x);
        int len = s.length();
        long long ans = 0;

        for(int i = 0;i<n;i++){
            mp[to_string(nums[i])]++;
        }

        for(int i = 1;i<len;i++){
            string a = s.substr(0,i);
            string b = s.substr(i,len - i);
            if(a == b) ans += (long long)(mp[a]*(mp[b] - 1));
            else ans += (long long)(mp[a]*mp[b]);
        }

        return ans;
    }
}; 

// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends