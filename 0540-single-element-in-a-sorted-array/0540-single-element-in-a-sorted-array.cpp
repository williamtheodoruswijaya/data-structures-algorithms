class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) mid -= 1;
            
            if (mid >= 0 && nums[mid-1] == nums[mid]) {
                left = mid + 1;
            } else if (mid >= 0 && nums[mid-1] != nums[mid]) {
                right = mid - 1;
            }
        }
        return nums[left];
    }
};