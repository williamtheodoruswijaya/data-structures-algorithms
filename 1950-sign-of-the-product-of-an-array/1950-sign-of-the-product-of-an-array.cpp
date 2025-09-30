class Solution {
public:
    int arraySign(vector<int>& nums) {
        int countMinus = 0;
        for (int num : nums) {
            if (num < 0) {
                countMinus++;
            } else if (num == 0) {
                return 0;
            }
        }
        return countMinus % 2 == 0 ? 1 : -1;
    }
};