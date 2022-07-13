// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


int max_sum(int a[],int n){
    int sum = 0, comp = 0, ans = 0;
    
    for(int i = 0;i < n;i++){
        sum += a[i];
        comp += a[i] * i;
    }
    
    for(int i = n - 1;i >= 0;i--){
        comp += sum - (a[i] * n);
        
        ans = max(ans, comp);
    }
    
    return ans;
}