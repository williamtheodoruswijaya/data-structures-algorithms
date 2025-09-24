class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == "") return true;

        vector<char> stack;
        for (int i = s.size() - 1; i >= 0; i--) {
            stack.push_back(s[i]);
        }

        for (char ch : t) {
            if (!stack.empty() && ch == stack.back()) stack.pop_back();
        }

        return stack.empty();
    }
};