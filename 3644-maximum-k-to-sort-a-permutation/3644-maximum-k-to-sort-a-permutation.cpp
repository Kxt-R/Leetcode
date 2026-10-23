class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int ans=~0;
        bool flag=false;
        for(int i=0;i<n;++i){
            if(nums[i]!=i) {
                ans&=nums[i];
                flag=true;
            }
        }
        if(!flag) return 0;
        return ans;
    }
};