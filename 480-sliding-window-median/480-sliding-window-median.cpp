class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k){
        multiset<long long> s1, s2;
        vector<double> ans;
        for(int i = 0;i<nums.size();i++){
            if(s1.empty()) s1.insert(nums[i]);
            else{
                auto u = s1.end();
                u--;

                if(nums[i] >= *u){
                    if((int) s1.size() == (int) s2.size()){
                        if(nums[i] > *s2.begin()){
                            s2.insert(nums[i]);
                            s1.insert(*s2.begin());
                            s2.erase(s2.begin());
                        }
                        else s1.insert(nums[i]);
                    }
                    else if((int) s1.size() > (int) s2.size()) s2.insert(nums[i]);
                }
                else{
                    if((int) s1.size() == (int) s2.size()) s1.insert(nums[i]);
                    else if((int) s1.size() > (int) s2.size()){
                        s1.insert(nums[i]);
                        s2.insert(*u);
                        s1.erase(s1.find(*u));
                    }
                }
            }

            if(i + 1 >= k){
                auto u = s1.end();
                u--;
                if(k % 2) ans.push_back((double)*u);
                else{
                    auto r = s2.begin();
                    long double x = (*u + *r)/2.0;
                    ans.push_back(x);
                }

                u = s2.find(nums[i - k + 1]);
                if(u != s2.end()){
                    s2.erase(u);
                }
                else {
                    u = s1.find(nums[i - k + 1]);
                    s1.erase(u);
                    if((int) s1.size() < (int) s2.size()){
                        s1.insert(*s2.begin());
                        s2.erase(s2.begin());
                    }
                }
            }
        }
        return ans;
    }
};