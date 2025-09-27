class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> stack;

        vector<int> res(temperatures.size(), 0);
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while (!stack.empty() && temperatures[stack.back()] <= temperatures[i]) stack.pop_back();
            if (stack.empty()) {
                res[i] = 0;
            } else {
                res[i] = stack.back() - i; // write the jarak between current element and next greater element
            }
            stack.push_back(i);
        }

        return res;
    }
};