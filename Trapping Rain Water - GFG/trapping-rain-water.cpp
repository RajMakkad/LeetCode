// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int a[], int n){
        vector<int> s(n,0), p(n,0);
        p[0] = a[0];
        s[n - 1] = a[n - 1];
        
        for(int i = 1;i<n;i++) p[i] = max(p[i - 1] , a[i]);
        for(int i = n - 2;i>=0;i--) s[i] = max(s[i + 1], a[i]);
        
        long long sum = 0;
        
        for(int i = 1;i<n - 1;i++){
            sum += (min(p[i],s[i]) - a[i]);
        }
        return sum;
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends