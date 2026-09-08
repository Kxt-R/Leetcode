class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long lower=1000;
        unsigned long long upper;
        long long k=0;
        while(1){
            if(n<lower) break;
            upper=1000*lower;
            k++;
            if(n<upper){
                ans+=k*(n-lower+1);
            }
            else{
                ans+=k*(upper-lower);
            }
            lower*=1000;
        }
        return ans;
    }
};