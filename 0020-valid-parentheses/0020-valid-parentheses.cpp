class Solution {
public:
    char match(char c){
        if(c=='}') return '{';
        else if(c==']') return '[';
        else return '(';
    }
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(c=='{' or c=='[' or c=='('){
                st.push(c);
            }
            else{
                if(!st.empty() and match(c)==st.top()) st.pop();
                else return false;
            }
        }
        if(st.size()>0) return false;
        return true;
    }
};