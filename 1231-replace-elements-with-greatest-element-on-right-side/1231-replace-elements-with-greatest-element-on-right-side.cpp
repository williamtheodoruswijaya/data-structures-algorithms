class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> stack, res(arr.size(), 0);

        for (int i= arr.size() - 1; i >= 0; i--) {
            if (stack.empty()) {
                res[i] = -1;
                stack.push_back(arr[i]);
                continue;
            }

            res[i] = stack.back();
            
            if (arr[i] > stack.back()) {
                stack.push_back(arr[i]);
            } 
        }

        return res;
    }
};