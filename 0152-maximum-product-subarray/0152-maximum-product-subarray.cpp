class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currmax=nums[0];
        int currmin=nums[0];
        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int num=nums[i];

            if(num<0) swap(currmax,currmin);

            currmax=max(num,currmax*num);
            currmin=min(num,currmin*num);

            ans=max(ans,currmax);
        }

        return ans;
    }
};