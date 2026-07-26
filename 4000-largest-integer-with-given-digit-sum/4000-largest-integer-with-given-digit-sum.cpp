class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9<s) return -1;
        int nn=s/9;
        int rem=s%9;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nn){
                ans=10*ans + 9;
                nn--;
            }
            else if(rem){
                ans=10*ans + rem;
                rem=0;
            }
            else ans=10*ans;
        }
        return ans;
    }
};