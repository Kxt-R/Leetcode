class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> v(n+1);
        for(auto x:shifts){
            if(x[2]==1){
                v[x[0]]++;
                v[x[1]+1]--;
            }
            else{
                v[x[0]]--;
                v[x[1]+1]++;
            }
        }
        for(int i=1;i<n;++i){
            v[i]+=v[i-1];
        }
        for(int i=0;i<n;++i){
            v[i]+=s[i]-'a';
            v[i]=((v[i]%26)+26)%26;
        }
        string ans="";
        for(int i=0;i<n;++i) ans.push_back('a'+v[i]);
        return ans;
    }
};