class Solution {
public:
    string removeStars(string s) {
        vector<char> stack;
        
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) stack.push_back(s[i]);
            else if (s[i] == '*') stack.pop_back();
        }

        string ans = "";
        for (char ch : stack) ans += ch;

        return ans;
    }
};