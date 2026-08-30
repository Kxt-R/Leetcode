class Solution {
public:
    const int MOD=1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long count=0;
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        if(sum>k) count=(sum-k-1)/k +1;
        return (((count%MOD)*((count+1)%MOD))/2)%MOD;
    }
};