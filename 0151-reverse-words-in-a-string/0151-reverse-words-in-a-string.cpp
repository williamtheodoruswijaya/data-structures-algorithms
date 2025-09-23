class Solution {
public:
    string reverseWords(string s) {
        // stack to store string and pop it reversely
        vector<string> stack;

        for (int i = 0; i < s.size(); i++) {
            // move i until it meet a numeric character
            while (isspace(s[i])) i++;

            // add it into a temp string
            string temp = "";
            while (isalnum(s[i])) {
                temp += s[i];
                i++;
            }

            // put temp into a stack only if temp
            if (temp != "") stack.push_back(temp);
        }

        string res = "";
        for (int i = stack.size() - 1; i >= 0; i--) {
            res += stack[i];
            if (i != 0) res += " ";
        }

        return res;
    }
};