class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int k=0;
        for(auto x:nums) k^=x;
        int idx=__builtin_ctz(k);
        int a=0,b=0;
        for(auto x:nums){
            if((x>>idx)&1) a^=x;
            else b^=x;
        }
        return {a,b};
    }
};