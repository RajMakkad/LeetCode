// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    void heapify(int a[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        
        if(left < n and a[left] > a[largest]){
            largest = left;
        } 
        
        if(right < n and a[right] > a[largest]){
            largest = right;
        }
        
        if(i != largest){
            swap(a[i], a[largest]);
            heapify(a, n, largest);
        }
    }

    public:
    void buildHeap(int a[], int n) {
        for(int i = n/2 - 1; i >= 0;i--){
            heapify(a, n, i);
        }
    }

    
    public:
    void heapSort(int a[], int n){
        buildHeap(a, n);
        
        for(int i = n - 1;i > 0;i--){
            swap(a[0], a[i]);
            heapify(a, i, 0);
        }
    }
};


// { Driver Code Starts.

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
  // } Driver Code Ends