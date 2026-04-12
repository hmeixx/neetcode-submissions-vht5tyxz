class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            } 
            else {
                if (sta.empty()) return false;

                char c = sta.top();
                sta.pop();

                if (s[i] == ')' && c != '(') return false;
                if (s[i] == '}' && c != '{') return false;
                if (s[i] == ']' && c != '[') return false;
            }
        }

        return sta.empty();
        
    }
};
