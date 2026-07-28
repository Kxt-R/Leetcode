class Solution {
public:
    static const int mod=1e9 +7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, mod - 2);
    }
    long long nCr(int n,int r,vector<long long> &fac,vector<long long> &invf){
        return (fac[n]*invf[r]%mod*invf[n-r]%mod)%mod;
    }
    int countValidSequences(int n, int k) {
        vector<long long> fac(n+1,1);
        for(int i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%mod;
        vector<long long > invf(n+1,1);
        invf[n]=modInverse(fac[n]);
        for(int i=n-1;i>0;i--) invf[i]=(invf[i+1]*(i+1))%mod;

        long long total=nCr(n-1,k-1,fac,invf);
        if((n-k)%2==1) return total%mod;
        int no_2=(n-k)/2;
        
        long long  odd=nCr(no_2+k-1,k-1,fac,invf);

        return (total-odd+mod)%mod;
    }
};