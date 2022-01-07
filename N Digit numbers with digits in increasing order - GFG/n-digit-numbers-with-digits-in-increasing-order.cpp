// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{
    vector<int> ans;
    void generate(int &index,int start,int num,int &n){
        if(index>n){
            ans.push_back(num);
            return ;
        }

        for(int i = start;i<=9;i++){
            index++;
            generate(index,i + 1,num*10 + i,n);
            index--;
        }
    }
public:
    vector<int> increasingNumbers(int n){
        if(n == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int index = 1;
        int start = 1;
        int num = 0;

        generate(index,start,num,n);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}  // } Driver Code Ends