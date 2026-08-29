class Solution {
public:
    int n;
    void run(int i,vector<int> &v ,set<vector<int>> &ans,vector<int>& nums){
        if(i==n){
            vector<int> c=v;
            sort(c.begin(),c.end());
            ans.insert(c);
            return;
        }

        v.push_back(nums[i]);
        run(i+1,v,ans,nums);
        v.pop_back();
        run(i+1,v,ans,nums);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        set<vector<int>> ans;
        vector<int> v={};
        run(0,v,ans,nums);
        vector<vector<int>> an;
        for(auto x: ans) an.push_back(x);
        return an;
    }
};