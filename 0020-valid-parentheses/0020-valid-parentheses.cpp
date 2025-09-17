class Solution {
public:
    bool isValid(string s) {
        unordered_set<char> open_brackets = {'(', '{', '['};
        vector<char> stack;

        int top = 0;
        for (char ch : s) {
            if(open_brackets.find(ch) != open_brackets.end()) {
                stack.push_back(ch);
                top++;
            } else {
                if (top && ch == '}' && stack[top-1] == '{') {
                    stack.pop_back();
                } else if (top && ch == ']' && stack[top-1] == '[') {
                    stack.pop_back();
                } else if (top && ch == ')' && stack[top-1] == '(') {
                    stack.pop_back();
                } else {
                    return false;
                }
                top--;
            }
        }

        if (stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
};