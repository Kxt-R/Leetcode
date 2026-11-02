class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int i=1;
        while(i<n){
            int len=1;
            while(i<n and (nums[i]==nums[i-1]+1 or nums[i]==nums[i-1])){
                if(nums[i]==nums[i-1]+1) len++;
                i++;
            }
            ans=max(ans,len);
            i++;
        }
        return ans;
    }
};