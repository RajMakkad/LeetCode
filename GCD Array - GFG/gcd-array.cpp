//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, int k, vector<int> &a) {
        int sum = 0;
        for(auto &i: a) sum += i;
        
        vector<int> f;
        for(int i = 1;i * i <= sum;i++){
            if(sum % i == 0){
                f.push_back(i);
                if(i * i != sum) f.push_back(sum / i);
            }
        }
        
        
        sort(f.rbegin(), f.rend());
        for(auto &i: f){
            int cnt = k;
            int part = 0;
            
            for(int j = 0;j < n;j++){
                part += a[j];
                if(part % i == 0){
                    part = 0;
                    cnt--;
                }
                
                if(cnt == 0) return i;
            }
        }
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> arr(N);
        Array::input(arr,N);
        
        Solution obj;
        int res = obj.solve(N, K, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends