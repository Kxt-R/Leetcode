class Solution {
public:

    vector<int> solve(string s){
        if(s.size()<=2){
            vector<int> v;
            int d=stoi(s);
            v.push_back(d);
            return v;
        }
        vector<int> t;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' or s[i]=='+' or s[i]=='-'){
                vector<int> vr=solve(s.substr(i+1,s.size()-i-1));
                vector<int> vl=solve(s.substr(0,i));
                if(s[i]=='*'){
                    for(int j=0;j<vr.size();j++){
                        for(int k=0;k<vl.size();k++){
                            t.push_back(vr[j]*vl[k]);
                        }
                    }
                }
                else if(s[i]=='+'){
                    for(int j=0;j<vr.size();j++){
                        for(int k=0;k<vl.size();k++){
                            t.push_back(vr[j]+vl[k]);
                        }
                    }
                }
                else{
                    for(int j=0;j<vr.size();j++){
                        for(int k=0;k<vl.size();k++){
                            t.push_back(vl[k]-vr[j]);
                        }
                    }
                }
            }
        }
        return t;
    } 
    vector<int> diffWaysToCompute(string expression) {
        vector<int> v;
        v=solve(expression);
        return v;
    }
};