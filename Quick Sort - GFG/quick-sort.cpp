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
    
    void quickSort(int arr[], int low, int high){
        if(low < high){
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }
    
    public:
    int partition (int arr[], int low, int high){
        int pivot = arr[low];
        int s = low, e = high;
        
        while(e > s){
            while(s < high and arr[low] >= arr[s]) s++;
            while(arr[e] > arr[low]) e--;
            
            if(e > s) swap(arr[s], arr[e]);
        }
        
        swap(arr[low], arr[e]);
        return e;
    }
};


// { Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends