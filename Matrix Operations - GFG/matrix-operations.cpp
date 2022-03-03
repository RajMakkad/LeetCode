// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix){
        int n = matrix.size();
        int m = matrix[0].size();
        int x = 0;
        int y = 0;
        int d = 0;
        
        while(x < n and y < m and x >= 0 and y >= 0){
            if(matrix[x][y] == 1){
                d = (d + 1)%4;
                matrix[x][y] = 0;
            }
            
            if(d == 0) y++;
            else if(d == 1) x++;
            else if(d == 2) y--;
            else x--;
        }
        
        if(x >= n) x--;
        else if(x < 0) x++;
        else if(y < 0) y++;
        else if(y >= m) y--;
        
        return {x,y};
    }

};

// { Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}  // } Driver Code Ends