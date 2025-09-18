class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        /*
            iterate backwardly
            always push number to stack
            keep notes to remove number from stack before checking
            the number in top of the stack must always be larger than the number currently iterated
            so we removed are the number lower or equal than the number currently iterated
            it's okay to empty the stack, it it's empty, it means that are no larger number than the current temp
            we compute it as 0 instead
            oh, store the index only on stack since we can easily check the number on the temp using the index
        */

        // 1. create a zero vector with the same size as temperatures, and an empty stack
        vector<int> res(temperatures.size(), 0), stack;

        // 2. iterate backwardly
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            // 3. pop the stack if the element in stack are lower or equal than the current temperatures
            while (!stack.empty() && temperatures[stack[stack.size() - 1]] <= temperatures[i]) {
                stack.pop_back();
            }

            // 4. if we pop the stack until empty, it means there are no warmer temperature than the current
            if (stack.empty()) {
                res[i] = 0;
            // 5. if there are an element, it means that elements are warmer then the temperature we have
            } else {
                res[i] = stack[stack.size() - 1] - i;
            }

            // 6. always notes that the current temperature we iterate may larger than the previous temperature (if not, stack always getting popped on each iteration)
            stack.push_back(i);
        }

        // 7. return the results
        return res;
    }
};