class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        
        int n = nums1.size();
        int m = nums2.size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        for(int i = 0;i < n;i++){
            q.push({nums1[i] + nums2[0], i, 0});
        }
        
        int size = 0;
        while(size < k and !q.empty()){
            vector<int> sub = q.top();
            q.pop();
            
            ans.push_back({nums1[sub[1]], nums2[sub[2]]});
            
            if(sub[2] + 1 < m) {
                sub[0] = nums1[sub[1]] + nums2[sub[2] + 1];
                sub[2]++;
                
                q.push(sub);
            }
            
            size++;
        }
        
        return ans;
    }
};