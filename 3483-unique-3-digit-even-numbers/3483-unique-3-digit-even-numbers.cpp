class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int,int> m;
        for(auto x:digits){
            m[x]++;
        }
        int ans=0;
        for(int i=0;i<=9;i+=2){
            if(m[i]>0){
                m[i]--;
                for(int j=0;j<=9;j++){
                    if(m[j]>0){
                        m[j]--;
                        int count=0;
                        for(int k=1;k<=9;k++) if(m[k]>0) count++;
                        ans+=count;
                        m[j]++;
                    }
                }
                m[i]++;
            }
        }
        return ans;
    }
};