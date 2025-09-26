class Solution {
public:
    string decodeString(string s) {
        vector<char> stack;

        for (char ch : s) {
            if (ch != ']') {
                stack.push_back(ch);
            } else {
                string temp = "";
                while (!stack.empty() && stack.back() != '[') {
                    temp += stack.back();
                    stack.pop_back();
                }

                reverse(temp.begin(), temp.end());

                if (stack.back() == '[') stack.pop_back();

                string forNum = "";
                while (!stack.empty() && isdigit(stack.back())) {
                    forNum += stack.back();
                    stack.pop_back();
                }
                
                reverse(forNum.begin(), forNum.end());

                int num = stoi(forNum);

                while (num--) {
                    for (int i = 0; i < temp.size(); i++) {
                        stack.push_back(temp[i]);
                    }
                }
            }
        }

        string ans = "";
        while (!stack.empty()) {
            ans += stack.back();
            stack.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};