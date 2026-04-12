class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        char c;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                sta.push(s[i]);
            }
            if(sta.empty()) return false;
            else{
                if(s[i] == ')' ){
                // pop() 在 C++ 是 沒有回傳值的
                c = sta.top();
                sta.pop();
                if(c!='('){
                    return false;
                }
            }
            else if(s[i] == '}' ){
                c = sta.top();
                sta.pop();
                if(c!='{'){
                    return false;
                }
            }
            else if(s[i] == ']' ){
                c = sta.top();
                sta.pop();
                if(c!='['){
                    return false;
                }
            }

            }
            
        }
        if(sta.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};
