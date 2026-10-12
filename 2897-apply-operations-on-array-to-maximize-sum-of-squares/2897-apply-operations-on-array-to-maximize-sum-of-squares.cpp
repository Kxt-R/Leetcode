class Solution {
public:
    void get_bit(int n,vector<int>&cnt){
        int bit=0;
        int c= 32;
        for(int i=0;i<32;i++){
            if((n&(1<<bit)))cnt[i]++;
            bit++;
        }
    }
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
         const long long MOD = 1e9 + 7;
        vector<int>cnt(32,0);
        for(int i : nums){
         get_bit(i,cnt);
        }
      long long ans=0;
        while(k--){
              long long cur=0;
            for(int i=31;i>=0;i--){
                if(cnt[i]>0){
                    cur|=(1<<i);
                    cnt[i]--;
                }
            }
      ans = (ans + cur * cur % MOD) % MOD;
        }
        return ans;
    }
};