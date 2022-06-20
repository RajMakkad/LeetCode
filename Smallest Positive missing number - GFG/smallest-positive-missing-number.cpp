// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution{
    public:
    int missingNumber(int a[], int n) { 
        for(int i = 0;i < n;i++){
            while(a[i] < n and a[i] >= 0 and a[i] != a[a[i]]){
                swap(a[i], a[a[i]]);
            }
        }

        for(int i = 1;i<n;i++){
            if(a[i] != i) return i;
        }
        
        if(a[0] == n) n++;
        
        return n;
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends