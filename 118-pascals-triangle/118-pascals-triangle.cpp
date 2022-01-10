class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        triangle[0] = {1};

        for(int i = 1;i<numRows;i++){
            triangle[i].resize(i + 1);
            triangle[i][0] = triangle[i - 1][0];
            triangle[i][i] = triangle[i - 1][i - 1];

            for(int it = 1;it<i;it++){
                triangle[i][it] = triangle[i - 1][it - 1] + triangle[i - 1][it];
            }
        }

        return triangle;
    }
};