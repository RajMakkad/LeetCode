class Solution {
    int vis[100000];
public:
    bool canReach(vector<int>& arr, int s){
        int n = arr.size();
        if(arr[s] == 0) return true;
        if(vis[s] == 1) return false;
        vis[s] = 1;
        
        bool a = false;
        bool b = false;

        if(s - arr[s] >= 0) a = canReach(arr,s - arr[s]);
        if(s + arr[s] < n) b = canReach(arr,s + arr[s]);

        return a || b ;
    }
};