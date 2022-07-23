#define ff first
#define ss second

class Solution {
    vector<int> ans;
    void merge(vector<pair<int, int>> &v, int s, int m, int e){
        int size = e - s + 1, p = m + 1;
        
        vector<pair<int, int>> sub(size);
        int cnt = 0, idx = 0, idx1 = s;
        
        while(s <= m and p <= e){
            if(v[s].ff > v[p].ff){
                cnt++;
                sub[idx++] = v[p++];
            }
            else {
                ans[v[s].ss] += cnt;
                sub[idx++] = v[s++];
            }
        }
        
        while(s <= m){
            ans[v[s].ss] += cnt;
            sub[idx++] = v[s++];
        }
        
        while(p <= e) sub[idx++] = v[p++];
        
        for(int i = 0;i < size;i++){
            v[i + idx1] = sub[i];
        }
    }
    void mergeSort(vector<pair<int, int>> &v, int s, int e){
        if(s >= e) return ;
        
        int m = s + (e - s)/2;
        
        mergeSort(v, s, m);
        mergeSort(v, m + 1, e);
        
        merge(v, s, m, e);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        for(int i = 0;i < n;i++){
            v[i].ff = nums[i];
            v[i].ss = i;
        }
        
        ans.resize(n);
        mergeSort(v, 0, n - 1);
        
        return ans;
    }
};