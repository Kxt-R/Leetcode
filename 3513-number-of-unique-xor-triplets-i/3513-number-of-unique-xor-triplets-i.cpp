class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int ans=1;
        while(1){
            if(n/ans==0) break;
            ans*=2;
        }
        return ans;
    }
};