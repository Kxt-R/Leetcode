class Solution {
public:
    char strt(int i){
        if(i==2) return 'a';
        else if(i==3) return 'd';
        else if(i==4) return 'g';
        else if(i==5) return 'j';
        else if(i==6) return 'm';
        else if(i==7) return 'p';
        else if(i==8) return 't';
        else return 'w';
    }
    void run(int idx,string &digit,string &s,vector<string> &ans){
        if(idx>=digit.size()){
            ans.push_back(s);
            return;
        }
        int d=digit[idx]-'0';
        char start=strt(d);
        int n=3;
        if(start=='p' or start=='w') n=4;
        for(int i=0;i<n;i++){
            s.push_back(char(start+i));
            run(idx+1,digit,s,ans);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        string s="";
        vector<string> ans;
        run(0,digits,s,ans);
        return ans;
    }
};