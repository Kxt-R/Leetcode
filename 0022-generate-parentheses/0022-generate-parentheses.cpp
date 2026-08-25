class Solution {
public:
    void helper(int n,int count,string &s,vector<string> &ans){
        if(count==0 and n==0) {
            ans.push_back(s);
            return;
        }
        if(count>0) {
            s.push_back(')');
            helper(n,count-1,s,ans);
            s.pop_back();
        }
        if(n>0) {
            s.push_back('(');
            helper(n-1,count+1,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        helper(n,0,s,ans);
        return ans;
    }
};