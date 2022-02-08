// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    static bool sortBit(int a,int b){
        int count_a = 0;
        int count_b = 0;
        
        while(a){
            count_a += (a&1);
            a = a >> 1;
        }
        
        while(b){
            count_b += (b&1);
            b = b >> 1;
        }
        
        return count_a > count_b;
    }
    
    public:
    void sortBySetBitCount(int arr[], int n){
        stable_sort(arr,arr + n,sortBit);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends