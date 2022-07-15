// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends

void solve(int x, int y, int n, string s, vector<string> &v){
    if(x == n and y == n){
        v.push_back(s);
        return ;
    }
    
    if(x < n) solve(x + 1, y, n, s + '(', v);
    if(y < x) solve(x, y + 1, n, s + ')', v); 
}
class Solution{
    public:
    vector<string> AllParenthesis(int n) {
        vector<string> v;
        string s = "";
        
        int x = 0, y = 0;
        
        solve(x, y, n, s, v);
        
        return v;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends