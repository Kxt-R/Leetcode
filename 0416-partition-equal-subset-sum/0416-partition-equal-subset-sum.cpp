class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%2==1) return false;
        bitset<10005> bit;
        bit[0]=1;
        int sum=total/2;
        for(auto ele : nums){
            bit|= (bit<<ele);
        }
        if(bit[sum]) return 1;
        else return 0;
    }
};