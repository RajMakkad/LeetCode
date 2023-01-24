//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution{
public:	

	void convert(int arr[], int n) {
	    pair<int, int> sub[n];
	    for(int i = 0;i < n;i++){
	        sub[i] = {arr[i], i};
	    }
	    
	    sort(sub, sub + n);
	    for(int i = 0;i < n;i++){
	        arr[sub[i].second] = i;
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends