class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for(int i=0;i<m-1;++i){
            string a=".";
            a.append(n-1,'#');
            ans.push_back(a);
        }
        string a(n,'.');
        ans.push_back(a);
        return ans;
    }
};