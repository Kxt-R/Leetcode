class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int cmax=0,maxsm=nums[0];
        int cmin=0,minsm=nums[0];
        int total=0; 

        for(auto ele :nums){
            total+=ele;
            
            cmax=max(ele,ele+cmax);
            maxsm=max(cmax,maxsm);

            cmin=min(ele,ele+cmin);
            minsm=min(cmin,minsm);
        }

        if(maxsm<0) return maxsm;

        return max(maxsm,total-minsm);
    }
};