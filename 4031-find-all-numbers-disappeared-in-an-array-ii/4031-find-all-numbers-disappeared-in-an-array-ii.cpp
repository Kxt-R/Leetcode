class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int prev=lower;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<prev) continue;
            if(nums[i]>upper) break;
            else if(nums[i]>prev){
                ans.push_back({prev,nums[i]-1});
            }
            prev=nums[i]+1;
        }
        if(prev<=upper){
            ans.push_back({prev,upper});
        }
        return ans;
    }
};