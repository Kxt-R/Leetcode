class Solution {
public:
    void run(int idx,string &s,string &curr,int &maxlen,unordered_set<string> &st,int count){
        if(count<0) return;
        if(idx==s.size()){
            if(count==0){
                if(curr.size()>maxlen){
                    maxlen=curr.size();
                    st.clear();
                }
                if(curr.size()==maxlen) st.insert(curr);
            }
            return;
        }


        if(s[idx]!=')' and s[idx]!='('){
            curr.push_back(s[idx]);
            run(idx+1,s,curr,maxlen,st,count);
            curr.pop_back();
        }
        else{
            curr.push_back(s[idx]);
            run(idx+1,s,curr,maxlen,st,count+(s[idx] == '(' ? 1 : -1));
            curr.pop_back();
            run(idx+1,s,curr,maxlen,st,count);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        vector<string> ans;
        string curr="";
        int maxlen=0;
        run(0,s,curr,maxlen,st,0);
        for(auto ele:st) ans.push_back(ele);
        return ans;
    }
};