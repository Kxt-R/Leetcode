class Solution {
public:
    int n;
    void run(int strt,vector<int> &v ,vector<vector<int>> &ans,vector<int>& nums){
        ans.push_back(v);
        for(int i=strt;i<n;i++){
            if(i>strt and nums[i]==nums[i-1]) continue;
            v.push_back(nums[i]);
            run(i+1,v,ans,nums);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v={};
        run(0,v,ans,nums);
        return ans;
    }
};