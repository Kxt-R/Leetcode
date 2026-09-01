class Solution {
public:
    vector<vector<string>> ans;
    bool check(int i,int j,string &s){
        while(i<j){
            if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void run(int idx,vector<string> &cand,string &s){
        if(idx==s.size()){
            ans.push_back(cand);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(check(idx,i,s)){
                string t=s.substr(idx,i-idx+1);
                cand.push_back(t);
                run(i+1,cand,s);
                cand.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cand;
        run(0,cand,s);
        return ans;
    }
};