class Solution {
public:
    int minInsertions(string s) {
        int count=0,ans=0;
        int n=s.size();
        for(int i=0;i<n;++i){
            if(s[i]=='(') {
                if(count%2==1){
                    ans++;
                    count--;;
                }
                count+=2;
            }
            else count--;
            if(count==-1){
                if(i+1<n and s[i+1]==')'){
                    ans++;
                    i++;
                }
                else ans+=2;
                count=0;
            }
        }
        ans+=count;
        return ans;
    }
};