class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, ans = INT_MIN, countOne = 0;

        for (int right = 0; right < nums.size(); right++) {
            // expand and track the number of one
            if (nums[right] == 1) countOne++;

            // shrink if the number of element we need to change > k available elements
            while (left <= right && right - left + 1 - countOne > k) {
                if (nums[left] == 1) countOne--;
                left++;
            }

            // update length
            int length = right - left + 1;
            ans = max(ans, length);
        }
        return ans;
    }
};