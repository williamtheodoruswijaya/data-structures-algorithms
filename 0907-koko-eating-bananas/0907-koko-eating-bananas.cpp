class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        /*
        Intuition: decide the search spaces, we know that the search spaces will be k.
        What's the upperbound of k? ofc the maximum number of piles banana that are in the piles.
        How about the lowerbound? we can conclude that k = 1 is probably the minimum value k can have.
        This will be our first step, find max of the piles to be the upperbound.
        Then, we will have a search space like this:
            let n = max(piles)
            search_spaces = [1,2,3,4,...,n]
        Next, we can perform a binary search to search for the most minimum k.
        The Hints is: THE MOST OPTIMAL K IS THE K THAT CAN GET "h" TO THE LOWEST AFTER EATING THOSE BANANA.
        Therefore, after we do a binary search, we can move the upper bound and lower bound.
        How to get the conditions? just simulate the process of koko eating the bananas that's it.
        */

        // step 1: find max from the piles
        int max = INT_MIN;
        for (int pile : piles) {
            if (pile > max) max = pile;
        }

        // step 2: do a binary search
        int left = 1, right = max;
        while (left <= right) {
            // 2.1. assumes we get k
            long long int k = left + (right - left) / 2;

            // 2.2  simulate the eating process (we can just divide each pile with k and ceil it up)
            //      if we sum all of the division, we can check if the sum > h, that means k is not enough, viceversa
            long long int sum = 0;
            for (int pile : piles) {
                sum += ceil((double)pile / (double)k);
            }

            // 2.3 if sum > h, that means k is not enough, move the lower bound (VICE VERSA)
            if (sum > h) {
                left = k + 1;
            } else {
                right = k - 1;
            }
        }

        // step 3: if the binary search has stop, we can take left (since left > right) as the minimum k can get
        return left;
    }
};