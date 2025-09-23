class Solution {
public:
    int findMax(vector<int> maps) {
        int max = INT_MIN;
        for (int num : maps) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    int characterReplacement(string s, int k) {
        vector<int> maps(27, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            // step 1: add maps
            maps[s[right] - 'A']++;

            // step 2: find max freq
            int maxFreq = findMax(maps);

            // step 3: check if window is valid (if not shrink)
            while (left < right && right - left + 1 - maxFreq > k) {
                maps[s[left] - 'A']--;
                left++;
                maxFreq = findMax(maps);
            }

            // step 4: update ans to the max length
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};