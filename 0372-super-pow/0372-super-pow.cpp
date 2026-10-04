class Solution {
public: 
    const static int MOD=1337;
    void div2(vector<int> &b,int &msd){
        int borrow=0;
        for(int i=msd;i<b.size();i++){
            if(borrow==1) b[i]+=10;
            borrow=(b[i]%2==1) ? 1 : 0;
            b[i]=b[i]/2;
        }
        while(msd<b.size() and b[msd]==0) {
            msd++;
        }
        return;
    }
    int superPow(int a, vector<int>& b) {
        a=a%MOD;
        int n=b.size();
        int msd=0;
        while(msd<b.size() and b[msd]==0) {
            msd++;
        }
        int res=1;
        while(msd<n){
            if(b[n-1]%2==1) res=(res*a)%MOD;
            a=(a*a)%MOD;
            div2(b,msd);
        }
        return res;
    }
};