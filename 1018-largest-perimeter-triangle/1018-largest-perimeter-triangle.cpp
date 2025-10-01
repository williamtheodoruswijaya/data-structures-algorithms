class Solution {
public:
    bool isTriangle(int a, int b, int c) {
        if (a + b <= c) return false;
        if (a + c <= b) return false;
        if (b + c <= a) return false;

        return true;
    }

    int largestPerimeter(vector<int>& nums) {
        // step 1: sort the nums
        sort(nums.begin(), nums.end());

        // step 2: create a 3-sized sliding window (expand first)
        vector<int> list;
        for (int right = 0; right < nums.size(); right++) {
            if (right == 3) break;
            list.push_back(nums[right]);
        }

        // step 3: check if the window can be created as a triangle
        int ans = INT_MIN;
        if (list.size() == 3) {
            int a = list[0], b = list[1], c = list[2];
            if (isTriangle(a,b,c)) ans = max(ans, a+b+c);
        } else {
            return 0;
        }

        // step 4: move the window
        int left = 0;
        for (int right = 3; right < nums.size(); right++) {
            // expand window
            list.push_back(nums[right]);

            // shrink left
            if (right - left + 1 > 3) {
                list.erase(list.begin() + 0);
                left++;
            }

            // calculate ans
            if (isTriangle(list[0], list[1], list[2])) {
                ans = max(ans, list[0]+list[1]+list[2]);
            }
        }

        return ans == INT_MIN ? 0 : ans;
    }
};