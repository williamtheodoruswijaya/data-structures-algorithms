class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> maps;
        vector<int> stack;

        vector<int> res(nums1.size(), 0);
        for(int i = nums2.size() - 1; i >= 0; i--) {
            // makesure the last element on stack is always greater than the current number
            while (!stack.empty() && stack.back() < nums2[i]) {
                stack.pop_back();
            }

            // if stack are empty, we can conclude that number to be the greatest element
            if (stack.empty()) maps[nums2[i]] = -1;

            // else, if there are element in stack which stack.back > nums2[j], map it to that number
            else maps[nums2[i]] = stack.back();

            // makesure to always push the current iterated number to stack
            stack.push_back(nums2[i]);
        }

        // map res based on nums1 and the value on maps
        for (int i = 0; i < nums1.size(); i++) {
            res[i] = maps[nums1[i]];
        }

        // return res
        return res;
    }
};