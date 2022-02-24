// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends

// class Solution{   
// public:
//     string moveRobots(string s1, string s2){
//         if(s1.length() != s2.length()) return "No";

//         int n = s1.length();
//         int a = 0;
//         vector<int> p;

//         for(int i = n - 1;i>=0;i--){
//             if(s1[i] == 'A') a++;
//             else if(s1[i] == 'B')  p.push_back(a);
//         }

//         reverse(p.begin(),p.end());
//         a = 0;
//         for(int i = n - 1;i>=0;i--){
//             if(s2[i] == 'A') a++;
//             else if(s2[i] == 'B'){
//                 if(p.back() != a) return "No";
//                 else p.pop_back();
//             }
//         }

//         vector<int> a_1,b_1;
//         for(int i = 0;i<n;i++){
//             if(s1[i] == 'A') a_1.push_back(i);
//             else if(s1[i] == 'B') b_1.push_back(i);
//         }

//         for(int i = n - 1;i>=0;i--){
//             if(s2[i] == 'A' and a_1.back() >= i) a_1.pop_back();
//             else if(s2[i] == 'B' and b_1.back() <= i) b_1.pop_back();
//         }

        
//         if(!a_1.empty() || !b_1.empty()) return "No";
//         else return "Yes";
//     }
// };

class Solution{   
public:
   string moveRobots(string s1, string s2){
      int l1 = 0;
      int l2 = 0;
      int n = s1.size();
      while(l1 < n && l2 < n){
            while(l1 < n && s1[l1] == '#')
               l1++;
            while(l2 < n && s2[l2] == '#')
               l2++;
            if(s1[l1] != s2[l2])
               return "No";
            else{
                if(s1[l1] == 'A'){
                    if(l1 >= l2)
                       l1++,l2++;
                    else
                      return "No";
                }
                else{
                     if(l1 <= l2)
                       l1++,l2++;
                     else
                       return "No";
                }
            }
      }
      
      return "Yes";
   }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        
        Solution ob;
        cout << ob.moveRobots(s1, s2) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends