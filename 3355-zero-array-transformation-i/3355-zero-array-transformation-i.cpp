class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> diff(n+1,0);
        for(auto &q:queries){
            diff[q[0]]--;
            diff[q[1]+1]++;
        }
        for(int i=1;i<n;++i) diff[i]+=diff[i-1];
        for(int i=0;i<n;i++){
            if(diff[i]+nums[i]>0) return false;
        }
        return true;
    }
};