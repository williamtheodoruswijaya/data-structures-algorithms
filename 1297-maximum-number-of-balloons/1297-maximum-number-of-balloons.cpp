class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> maps;
        for (char ch : text) {
            maps[ch]++;
        }

        if (maps.find('l') != maps.end()) maps['l'] /= 2;
        if (maps.find('o') != maps.end()) maps['o'] /= 2;
        
        int ans = 9999;
        string balloon = "balloon";
        for (char ch : balloon) {
            ans = min(ans, maps[ch]);
        }

        return ans;
    }
};

/*
    NAIVES SOLUTIONS:

    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> balloonMaps = {
            {'b', 1},
            {'a', 1},
            {'l', 2},
            {'o', 2},
            {'n', 1}
        };
        unordered_map<char, int> constantMaps = balloonMaps;

        int ans = 0;
        for (char ch : text) {
            if (balloonMaps.find(ch) == balloonMaps.end()) continue;
            if (balloonMaps[ch] > 0) balloonMaps[ch]--;
            if (balloonMaps[ch] <= 0) balloonMaps.erase(ch);
            if (balloonMaps.empty()) {
                ans += 1;
                balloonMaps = constantMaps;
            }
        }

        return ans;
    }
*/