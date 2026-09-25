class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int idx = 0;
        set<string> res = parseExpr(expression, idx);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> parseExpr(const string& s, int& idx) {
        set<string> res;
        while (idx < s.length() && s[idx] != '}') {
            set<string> term = parseTerm(s, idx);
            res.insert(term.begin(), term.end());
            if (idx < s.length() && s[idx] == ',') {
                idx++;
            }
        }
        return res;
    }

    set<string> parseTerm(const string& s, int& idx) {
        set<string> res = {""};
        while (idx < s.length() && s[idx] != '}' && s[idx] != ',') {
            set<string> factor = parseFactor(s, idx);
            set<string> next;
            for (const string& a : res) {
                for (const string& b : factor) {
                    next.insert(a + b);
                }
            }
            res = move(next);
        }
        return res;
    }

    set<string> parseFactor(const string& s, int& idx) {
        if (s[idx] == '{') {
            idx++;
            set<string> res = parseExpr(s, idx);
            idx++;
            return res;
        } 
        else {
            set<string> res = {string(1, s[idx])};
            idx++;
            return res;
        }
    }
};