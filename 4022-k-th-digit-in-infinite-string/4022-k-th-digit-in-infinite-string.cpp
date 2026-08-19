class Solution {
public:
    int kthDigit(long long k) {
        k--;
        long long f=1;
        long long d=1;
        while(1){
            long long sub=(1LL)*9*f*d;
            if(sub>=k){
                break;
            }
            k-=sub;
            f*=10;
            ++d;
        }
        long long no=k/d;
        long long rem=(k)%(d);
        long long actual=f+no;
        if((actual/10)%2==1){
            int r=actual%10;
            actual=actual+9-(2*r);
        }
        string s=to_string(actual);
        char a=s[rem];
        int ans=a-'0';
        return ans;
    }
};