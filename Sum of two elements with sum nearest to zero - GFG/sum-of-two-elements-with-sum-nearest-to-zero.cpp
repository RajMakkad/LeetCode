// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        int closestToZero(int a[], int n){
            sort(a, a + n);
            int s = 0, e = n - 1;
            
            pair<int, int> ans = {1e7, -100000000};
            while(e > s){
                int sum = a[s] + a[e];
                int d = abs(sum);
                
                if(ans.first > d) ans = {d, sum};
                else if(ans.first == d) ans.second = max(ans.second, sum);
                
                if(sum >= 0) e--;
                else s++;
            }
            
            return ans.second;
        }
};

// { Driver Code Starts.
int main ()
{
    int t; 
    cin >> t;
    while (t--)
    {
        int n; 
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.closestToZero(arr, n) << endl;
    }
}  // } Driver Code Ends