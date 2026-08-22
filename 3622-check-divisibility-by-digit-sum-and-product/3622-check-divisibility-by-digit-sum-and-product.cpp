class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,prod=1;
        int x=n;
        while(x){
            int rem=x%10;
            sum+=rem;
            prod*=rem;
            x/=10;
        }
        if(n%(sum+prod)==0) return 1;
        return 0;
    }
};