class Solution {
public:
    int possible(vector<int>& weights, int days, int capacity) {
        int boat = 0;
        for (int weight : weights) {
            if (boat + weight > capacity) {
                days--;
                boat = weight;
            } else if (boat + weight <= capacity) {
                boat += weight;
            }
        }

        if (boat != 0) days--;

        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        /*  1. decide what is the search space = ship capacity
            2. what's the lower bound and upper bound? lower bound = the minimum, upper bound = sum of all number
            3. how would you create the condition?
        */

        // step 1: find the upper bound
        int sum = 0;
        for (int weight : weights) {
            sum += weight;
        }

        // step 2: find the lower bound
        int max = INT_MIN;
        for (int weight : weights) {
            if (weight > max) max = weight;
        }

        // step 3: define the lower bound and upper bound and do a binary search
        int left = max, right = sum;
        while (left <= right) {
            // assumes capacity = mid we try to find
            long long int capacity = left + (right - left) / 2;

            // step 3: create the conditions
            int remainingDays = possible(weights, days, capacity);

            // step 4: if-else goes here
            if (remainingDays >= 0) {
                right = capacity - 1;
            } else {
                left = capacity + 1;
            }
        }

        return left;
    }
};