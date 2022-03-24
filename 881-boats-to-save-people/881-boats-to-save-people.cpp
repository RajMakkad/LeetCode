class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit){
        sort(people.begin(),people.end());
        int n = people.size();
        int x = 0;
        int y = n - 1;

        int ans = 0;

        while(y >= x){
            int sum = people[x] + people[y];
            if(x == y) sum = sum - people[x];
            if(limit >= sum){
                x++;
                y--;
            }
            else y--;
            ans++;
        }

        return ans;
    }
};