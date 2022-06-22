class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> q;
        for(int i = 1;i < heights.size();i++){
            if(heights[i] > heights[i - 1]){
                int d = heights[i] - heights[i - 1];
                q.push(d);
                bricks = bricks - d;
                
                while(bricks < 0 and ladders > 0){
                    bricks += q.top();
                    ladders--;
                    q.pop();
                }

                if(bricks < 0) return i - 1;
            }
        }

        return heights.size() - 1;
    }
};