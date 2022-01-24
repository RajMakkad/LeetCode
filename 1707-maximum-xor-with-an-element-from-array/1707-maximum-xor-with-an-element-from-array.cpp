class Solution{
    struct Node{
        Node *links[2];
        
        bool is_present(int p){
            return links[p] != NULL;
        }
        
        void insert(int p){
            links[p] = new Node();
        }
        
        Node *get(int p){
            return links[p];
        }
    };
    
    Node *root = new Node();
    
    void add(int num){
        Node *node = root;
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            
            if(node->is_present(p) == false){
                node->insert(p);
            }
            node = node->get(p);
        }
    }
    
    int getXor(int num){
        Node *node = root;
        int ans = 0;
        
        for(int i = 31;i>=0;i--){
            int p = (num>>i)&1;
            if(node->is_present(!p)){
                ans |= 1<<i;
                node = node->get(!p);
            }
            else node = node->get(p);
        }
        
        return ans;
    }
    
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1] < b[1];
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        int q = queries.size();
        vector<int> ans(q);
            
        for(int i = 0;i<q;i++) queries[i].push_back(i);
        sort(queries.begin(),queries.end(),comp);
        sort(nums.begin(),nums.end());
        
        int index = -1;
        for(int i = 0;i<q;i++){
            int max_xor = -1;
            auto u = upper_bound(nums.begin(),nums.end(),queries[i][1]) - nums.begin();
            while(index < u - 1){
                add(nums[++index]);
            }
            
            if(root->links[0] || root->links[1]) max_xor = getXor(queries[i][0]);
            ans[queries[i][2]] = max_xor;
        }
        
        return ans;
    }
};