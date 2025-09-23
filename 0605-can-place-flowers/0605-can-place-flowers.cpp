class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // edge-case:
        if (flowerbed.size() == 1) {
            if (flowerbed[0] == 0 && n >= 1) {
                n--;
            }
            return n == 0 ? true : false;
        }

        for (int i = 0; i < flowerbed.size(); i++) {
            // early return
            if (n == 0) return true;
            
            // case #1: if we want to plant on the most left side
            if (i == 0 && (flowerbed[i] == 0 && flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
            // case #2: if we want to plant on the most right side
            else if (i == flowerbed.size() - 1 && (flowerbed[i] == 0 && flowerbed[i-1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
            // case #3: if we want to plant on the middle
            else if ((i != 0 && i < flowerbed.size()) && flowerbed[i] == 0 && (flowerbed[i-1] == 0 && flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0 ? true : false;
    }
};