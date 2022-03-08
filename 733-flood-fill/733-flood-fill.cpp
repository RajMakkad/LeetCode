class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& img, int sr, int sc, int nC) {
        int n = img.size();
        int m = img[0].size();
        int colour;
        queue<pair<int,int>> q;
        if(img[sr][sc]!=nC){
            q.push({sr,sc});
            colour = img[sr][sc];
            img[sr][sc] = nC;
        }

        while(q.size()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            int dx[]={-1,0,1,0};
            int dy[]={0,-1,0,1};

            for(int i = 0;i<4;i++){
                int x1 = x + dx[i];
                int y1 = y + dy[i];

                if(x1>=0 and y1>=0 and x1<n and y1<m and img[x1][y1] == colour){
                    img[x1][y1] = nC;
                    q.push({x1,y1});
                }
            }
        }

        return img;
    }
};