class Solution {
public:
    int dp[102][102];
    int ring(int cur,int kcur,string &s, string &key){
        if(kcur==key.size()) return 0;
        if(dp[cur][kcur]!=-1) return dp[cur][kcur];

        int rightpath=0;
        int leftpath=0;
        int idxr=cur,idxl=cur;

        while(1){
            if(idxr==s.size()) idxr=0;
            if(s[idxr]==key[kcur]){
                rightpath++;
                break;
            }
            idxr++;
            rightpath++;
        }
        while(1){
            if(idxl==-1) idxl=s.size()-1;
            if(s[idxl]==key[kcur]){
                leftpath++;
                break;
            }
            idxl--;
            leftpath++;
        }
        return dp[cur][kcur]=min(rightpath + ring(idxr,kcur+1,s,key),leftpath +ring(idxl,kcur+1,s,key));
    }
    int findRotateSteps(string s, string key) {
        memset(dp,-1,sizeof dp);
        return ring(0,0,s,key);
    }
};