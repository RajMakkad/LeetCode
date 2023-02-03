//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void move(int &x, int &y, int &sign){
        if(sign == 0) y++;
        else if(sign == 1) x++;
        else if(sign == 2) y--;
        else x--;
    }
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int r, int c){
        int x, y, sign;
        x = y = sign = 0;
        
        int ans_x, ans_y;
        
        while(x >= 0 and y >= 0 and x < r and y < c){
            if(matrix[x][y] == 0) {
                ans_x = x;
                ans_y = y;
                
                move(x, y, sign);
            }
            
            else {
                matrix[x][y] = 0;
                sign = (sign + 1) % 4;
            }
        }
        
        return {ans_x, ans_y};
    }
};

//{ Driver Code Starts.


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
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends