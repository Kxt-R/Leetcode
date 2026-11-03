class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int sum=0;
        for(auto x:nums){
            sum+=mx-x;
        }
        return sum;
    }
};