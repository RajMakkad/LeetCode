// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
 
class Solution{
public:	
	ull getNthUglyNo(int n) {
	    ull i(1),i2(0),i3(0),i5(0);

		vector<ull> ugly(n);
		ugly[0] = 1;

		ull nm2 = 2*ugly[i2],nm3 = 3*ugly[i3],nm5 = 5*ugly[i5];

		for(int i = 1;i<n;i++){
			ull nexti = min({nm2,nm3,nm5});
			ugly[i] = nexti;

			if(nexti == nm2){
				i2++;
				nm2 = 2*ugly[i2];
			}
			if(nexti == nm3){
				i3++;
				nm3 = 3*ugly[i3];
			}
			if(nexti == nm5){
				i5++;
				nm5 = 5*ugly[i5];
			}
		}

		return ugly[n - 1];
	}
};



// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends