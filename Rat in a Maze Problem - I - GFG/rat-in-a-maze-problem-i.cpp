// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    bool isValid(int &x, int &y, int &n){
        return x >= 0 and y >= 0 and x < n and y < n;
    }
    void solve(int x, int y, string &s, vector<string> &ans, vector<vector<int>> &mat, int n){
        if(x == n - 1 and y == n - 1){
            ans.push_back(s);
            return ;
        }
        
        mat[x][y] = 0;
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};
        
        for(int i = 0;i< 4;i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            
            if(isValid(x1, y1, n) and mat[x1][y1] == 1){
                if(i == 0) s += 'L';
                else if(i == 1) s += 'U';
                else if(i == 2) s += 'R';
                else s += 'D';
                
                solve(x1, y1, s, ans, mat, n);
                
                s.pop_back();
            }
        }
        mat[x][y] = 1;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string s = "";
        vector<string> ans;
        
        if(m[0][0] == 1) solve(0, 0, s, ans, m, n);
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends