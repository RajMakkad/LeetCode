// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution{
    public:
    void merge(int arr[], int l, int m, int r){
        int x = l;
        int y = m + 1;
        int k = l;
        
        int b[r];
        
        while(x <= m || y <= r){
            if(x <= m and y <= r){
                if(arr[x] >= arr[y]) b[k++] = arr[y++];
                else b[k++] = arr[x++];
            }
            else if(x <= m) b[k++] = arr[x++];
            else b[k++] = arr[y++];
        }
        
        for(int i = l;i <= r;i++) arr[i] = b[i];
    }
    
    public:
    void mergeSort(int arr[], int l, int r){
        if(r > l){
            int m = l + (r - l)/2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            merge(arr, l, m, r);
        }
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends