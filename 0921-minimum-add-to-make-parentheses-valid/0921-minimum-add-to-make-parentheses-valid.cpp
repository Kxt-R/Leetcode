class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int count=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='(') count++;
            else {
                if(count>0) count--;
                else ans++;
            }
        }
        ans+=count;
        return ans;
    }
};