class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, ans = 0;
        for (int right = 0; right < prices.size(); right++) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            int profit = prices[right] - prices[left];
            ans = max(ans, profit);
        }
        return ans;
    }
};