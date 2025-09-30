class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size(), 0);

        // step 1: sort the spells
        sort(potions.begin(), potions.end());

        // step 2: perform binary search for each iterations
        for (int i = 0; i < spells.size(); i++) {

            // step 2.1: 
            int left = 0, right = potions.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                long long int power = (long) spells[i] * potions[mid];
                // step 2.1.1: since all elm after mid will be greater than success, we will include those elements in res and check for the left side.
                if (power >= success) {
                    res[i] += right - mid + 1;
                    right = mid - 1;
                } 
                // step 2.1.2: we will iterate for the left part
                else if (power < success) {
                    left = mid + 1;
                }
            }
        }

        return res;
    }
};