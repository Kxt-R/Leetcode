class Solution {
public:
    int run(int n,int k){
        if(n==1) return 0;

        int idx=run(n-1,k);
        idx+=k;
        return idx%n;
    }
    int findTheWinner(int n, int k) {
        return run(n,k)+1;
    }
};