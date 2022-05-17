class Solution {
public:
    int racecar(int target){
        queue<vector<int>> q;
        q.push({0,1,0}); // positon, speed, steps.

        while(q.size()){
            auto node = q.front();
            q.pop();

            if(node[0] == target) return node[2];

            if(abs(node[0]) > 2*target) continue;
            q.push({node[0] + node[1], 2*node[1], node[2] + 1});

            if((node[1] > 0 and node[0] + node[1] > target) || (node[1] < 0 and node[0] + node[1] < target)){
                q.push({node[0], (node[1] > 0 ? -1 : 1), node[2] + 1});
            }
        }

        return 0;
    }
};