class Solution {
public:
    int total_sum;
    bool dp[203][20003];
    bool visited[203][20003];
    int run(int idx,int sum,vector<int> &nums){
        if(idx==nums.size()) return false;

        if(total_sum==2*sum) return true;

        if(visited[idx][sum]) return dp[idx][sum];
        visited[idx][sum]=true;
        return run(idx+1,sum+nums[idx],nums) | run(idx+1,sum,nums);
    }
    bool canPartition(vector<int>& nums) {
        total_sum=0;
        for(auto ele: nums) total_sum+=ele;
        if(total_sum%2==1) return false;
        memset(dp,false,sizeof dp);
        memset(visited,false,sizeof visited);
        return run(0,0,nums);
    }
};