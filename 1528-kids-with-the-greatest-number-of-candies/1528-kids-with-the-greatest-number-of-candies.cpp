class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        // step 1: find max number in existing candies
        int maxCandies = INT_MIN;
        for (int candy : candies) {
            if (candy > maxCandies) {
                maxCandies = candy;
            }
        }

        // step 2: check for each candy, if candy + extraCandies < maxCandies, then it's false, otherwise true.
        vector<bool> res;
        for (int candy : candies) {
            if (candy + extraCandies < maxCandies) {
                res.push_back(false);
            } else {
                res.push_back(true);
            }
        }

        // step 3: return the results
        return res;
    }
};