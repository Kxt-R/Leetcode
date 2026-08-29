class Solution {
public:
    int kthGrammar(int n, int k) {
        int tn=n;
        vector<int> v(n+1);
        v[tn]=k;
        while(tn>1){
            v[tn-1]=(v[tn]+1)/2;
            tn--;
        }
        int c=0;
        for(int i=2;i<=n;i++){
            if(c==0){
                if(v[i]%2==0) c=1;
                else c=0;
            }
            else{
                if(v[i]%2==0) c=0;
                else c=1;
            }
        }
        return c;
    }
};