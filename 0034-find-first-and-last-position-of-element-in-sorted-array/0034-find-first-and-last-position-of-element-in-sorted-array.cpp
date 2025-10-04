class Solution {
public:
    int binarySearchLeftMost(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        int results = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                results = mid;
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return results;
    }

    int binarySearchRightMost(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        int results = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                results = mid;
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return results;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);

        res[0] = binarySearchLeftMost(nums, target);
        res[1] = binarySearchRightMost(nums, target);

        return res;
    }
};