class Solution {
public:
    int MAX=1000001;
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> v(MAX,0);
        int n=nums.size();
        for(int i=0;i<n;++i){
            if(nums[i]>0 and nums[i]<MAX) v[nums[i]]=1;
        }
        for(int i=1;i<MAX;++i) if(v[i]!=1) return i;
        return MAX;
    }
};