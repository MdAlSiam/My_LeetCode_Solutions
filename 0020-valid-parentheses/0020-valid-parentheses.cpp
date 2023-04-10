class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesisStack;

        map <char, char> inverse;
        inverse['('] = ')';
        inverse['{'] = '}';
        inverse['['] = ']';

        for (char ch : s) {
            if (ch == '(' or ch == '{' or ch == '[') {
                parenthesisStack.push(ch);
            }
            else {
                if (parenthesisStack.empty()) {
                    return false;
                }
                else if (inverse[parenthesisStack.top()] != ch) {
                    return false;
                }
                else {
                    parenthesisStack.pop();
                }
            }
        }

        if (parenthesisStack.empty()) return true;
        return false;
    }
};