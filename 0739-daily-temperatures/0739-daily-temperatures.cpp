class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0), stack;

        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!stack.empty() && temperatures[stack[stack.size() - 1]] <= temperatures[i]) {
                stack.pop_back();
            }

            if (stack.empty()) {
                res[i] = 0;
            } else {
                res[i] = stack[stack.size() - 1] - i;
            }

            stack.push_back(i);
        }
        return res;
    }
};