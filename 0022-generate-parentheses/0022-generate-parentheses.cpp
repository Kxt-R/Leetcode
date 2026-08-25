class Solution {
public:
    void helper(int n,int count,string s,vector<string> &ans){
        if(count==0 and n==0) {
            ans.push_back(s);
            return;
        }
        if(count>0) helper(n,count-1,s+')',ans);
        if(n>0) helper(n-1,count+1,s+'(',ans);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n,0,"",ans);
        return ans;
    }
};