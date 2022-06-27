// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends

class Solution{
  public:
    int tour(petrolPump p[],int n){
       int idx = 0;
       int sum = 0;
       int possible = 0;
       
       for(int i = 0;i < n;i++){
           sum += p[i].petrol;
           sum -= p[i].distance;
           
           if(sum < 0){
               idx = i + 1;
               sum = 0;
           }
           
           possible += (p[i].petrol - p[i].distance);
       }
       
       if(possible >= 0) return idx;
       return -1;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends