class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> stack;

        int index = 0;
        for (int i = 0; i < pushed.size(); i++) {
            stack.push_back(pushed[i]);

            while (!stack.empty() && index < popped.size() && stack.back() == popped[index]) {
                stack.pop_back();
                index++;
            }
        }

        return index == popped.size();
    }
};