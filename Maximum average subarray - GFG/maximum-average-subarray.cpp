// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int findMaxAverage(int a[], int n, int k){
        pair<int,int> ans = {-1e9,0};
        int sum = 0;

        for(int i = 0;i<n;i++){
            sum += a[i];
            if(i + 1 >= k){
                if(sum > ans.first) ans = {sum,i - k + 1};
                sum = sum - a[i - k + 1];
            }
        }

        return ans.second;
    }
};
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxAverage(arr, n, k);
        for (int i = ans; i < ans + k; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends