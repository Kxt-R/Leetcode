class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }
        string result;
        string key;
        bool inside = false;

        for (char c : s) {
            if (c == '(') {
                inside = true;
                key.clear();
            } else if (c == ')') {
                inside = false;
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
            } else if (inside) {
                key += c;
            } else {
                result += c;
            }
        }

        return result;
    }
};