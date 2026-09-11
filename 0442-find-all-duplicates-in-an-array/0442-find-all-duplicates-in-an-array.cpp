class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        for(auto x:nums){
            m[x]++;
            if(m[x]==2) ans.push_back(x);
        }
        return ans;
    }
};