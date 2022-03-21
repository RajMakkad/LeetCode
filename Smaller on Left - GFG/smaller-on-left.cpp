// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}// } Driver Code Ends


vector<int> Smallestonleft(int a[], int n){
    vector<int> ans(n);
    set<int> st;
    for(int i = 0;i<n;i++){
        st.insert(a[i]);
        auto u = st.lower_bound(a[i]);
        if(u != st.begin()){
            u--;
            ans[i] = *u;
        } 
        else ans[i] = -1;
    }

    return ans;
}