// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m) {
        unordered_map<int, int> mp;
        for(int i = 0;i < m;i++){
            if(mp.find(a2[i]) == mp.end()) mp[a2[i]] = i;
        }
        
        for(int i = 0;i < n;i++){
            if(mp.find(a1[i]) == mp.end()) mp[a1[i]] = m + a1[i];
        }
        
        sort(a1.begin(), a1.end(), [&](const int &x, const int &y){
            return mp[x] < mp[y];
        });
        
        return a1;
    } 
};

// { Driver Code Starts.

int main(int argc, char *argv[]) 
{ 
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m); 
	
	   
	    for (int i = 0; i < n; i++) 
		    cout<<a1[i]<<" ";
		
	    cout << endl;
	    
	    
	}
	return 0; 
} 
  // } Driver Code Ends