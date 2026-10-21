class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        string temp=s;
        sort(temp.begin(),temp.end());
        if(temp==s) return 0;
        if(n==2){
            if(s[0]>s[1]) return -1;
            else return 0;
        }
        if(s[0]==temp[0] or s[n-1]==temp[n-1]) return 1;
        for(int i=1;i<n-1;++i){
            if(s[i]==temp[0] or s[i]==temp[n-1]) return 2;
        }
        return 3;  
    }
};