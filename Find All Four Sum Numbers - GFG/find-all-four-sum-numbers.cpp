// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        for(int i = 0;i < n;i++){
            if(i > 0 and arr[i] == arr[i - 1]) continue;
            for(int j = i + 1;j < n;j++){
                if(j > i + 1 and arr[j] == arr[j - 1]) continue;
                int s = j + 1;
                int e = n - 1;
                
                while(e > s){
                    int sum = arr[i] + arr[j] + arr[s] + arr[e];
                    if(sum > k) e--;
                    else if(sum < k) s++;
                    else {
                        ans.push_back({arr[i], arr[j], arr[s], arr[e]});
                        s++;
                        while(s < e and arr[s] == arr[s - 1]) s++;
                    }
                }
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends