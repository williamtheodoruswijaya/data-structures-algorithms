class Solution {
public:
    int findPosition(vector<int>& res, int target) {
        int left = 0, right = res.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (res[mid] == target) {
                return mid;
            } else if (target < res[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;

        for (int num : nums) {
            int squaredNum = num * num;
            
            int pos = findPosition(res, squaredNum);

            res.insert(res.begin() + pos, squaredNum);
        }

        return res;
    }
};