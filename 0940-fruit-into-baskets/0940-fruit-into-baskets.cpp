class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> maps;

        int ans = 0, left = 0;
        for (int right = 0; right < fruits.size(); right++) {
            // add fruits to basket
            maps[fruits[right]]++;

            // shrink basket using left
            if (maps.size() > 2) {
                maps[fruits[left]]--;
                
                if (maps[fruits[left]] <= 0) {
                    maps.erase(fruits[left]);
                }

                left++;
            }

            // update answer per iteration (using windows length to track total of fruits)
            int total = right - left + 1;
            ans = max(ans, total);
        }

        return ans;
    }
};