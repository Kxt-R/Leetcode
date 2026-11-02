class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=1;i<n;++i){
            sum+=(nums[i]-nums[i-1])*min(i,n-i);
        }
        return sum;
    }
};