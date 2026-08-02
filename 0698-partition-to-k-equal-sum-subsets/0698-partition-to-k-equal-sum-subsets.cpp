class Solution {
public:
    int visited[20];
    int target;
    bool run(int idx,int sum,int k,vector<int> &v){
        if(k==1) return true;
        if(sum==target) return run(0,0,k-1,v);

        if(sum>target or idx>=v.size()) return false;

        if(run(idx+1,sum,k,v)) return true;
        if(!visited[idx]) {
            visited[idx]=true;
            if(run(idx+1,sum+v[idx],k,v)) return true;
            visited[idx]=false;
        }
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        memset(visited,false,sizeof visited);
        int total=accumulate(nums.begin(),nums.end(),0);
        if(total%k!=0) return false;
        target=total/k;
        if(*max_element(nums.begin(),nums.end())>target) return false;
        return run(0,0,k,nums);
    }
};