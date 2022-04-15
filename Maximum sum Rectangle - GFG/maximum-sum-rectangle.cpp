// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    int max_sum(vector<int> &a){
        int sum = 0;
        int ans = -1e9;

        for(int i = 0;i<a.size();i++){
            sum = max(a[i] + sum,a[i]);
            ans = max(ans,sum);
        }

        return ans;
    }
  public:
    int maximumSumRectangle(int n, int m, vector<vector<int>> mat){
        for(int r = 0;r<n;r++){
            for(int c = 1;c<m;c++){
                mat[r][c] += mat[r][c - 1];
            }
        }

        int ans = -1e9;
        for(int c1 = 0;c1<m;c1++){
            for(int c2 = c1;c2<m;c2++){
                vector<int> a(n);
                for(int r = 0;r<n;r++){
                    a[r] = mat[r][c2];
                    if(c1 > 0) a[r] -= mat[r][c1 - 1];
                }

                ans = max(ans,max_sum(a));
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
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends