class Solution {
    int targetPrefixSum(vector<int> &prefix,int &target){
        int n = prefix.size();
        int sub = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;

        for(int i = 0;i<n;i++){
            int remain = prefix[i] - target;
            sub += mp[remain];
            mp[prefix[i]]++;
        }

        return sub;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;

        for(int i = 0;i<n;i++){
            for(int j = 1;j<m;j++){
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for(int s = 0;s<m;s++){
            for(int e = s;e<m;e++){
                vector<int> prefix(n);
                for(int i = 0;i<n;i++){
                    prefix[i] = matrix[i][e] - ( s>0 ? matrix[i][s - 1] : 0);
                    if(i>0) prefix[i] += prefix[i - 1];
                }
                ans += targetPrefixSum(prefix,target);
            }
        }

        return ans;
    }
};