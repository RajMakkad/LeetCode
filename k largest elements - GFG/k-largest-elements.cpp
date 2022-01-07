// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	    priority_queue<int,vector<int>,greater<int>> q; 
        vector<int> kthLargest;

        for(int i = 0;i<n;i++){
            q.push(arr[i]);
            while(q.size() > k) q.pop();
        }

        while(q.size()){
            kthLargest.push_back(q.top());
            q.pop();
        }

        reverse(kthLargest.begin(),kthLargest.end());
        return kthLargest;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends