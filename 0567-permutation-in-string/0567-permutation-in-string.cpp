class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> counter1, counter2;

        // s-cases (if s1.size() > s2.size()) there's no way s2 have a substring which's a permutation of s1
        if (s1.size() > s2.size()) return false;

        // create the first maps based on s1 (for comparison)
        for (char ch : s1) {
            counter1[ch]++;
        }

        // check from first left to right on s2 (grow the window)
        int left = 0, right = s1.size() - 1;
        for (int i = left; i <= right; i++) {
            counter2[s2[i]]++;
        }

        // early checks
        if (counter1 == counter2) return true;
        
        // move the window
        while (right < s2.size()) {
            // delete current element pointed by left
            if (counter2.find(s2[left]) != counter2.end()) {
                counter2[s2[left]]--;

                if (counter2[s2[left]] <= 0) {
                    counter2.erase(s2[left]);
                }
            }
            // move left once
            left++;
            
            // move right once, add new element pointed by right to maps
            right++;
            counter2[s2[right]]++;
            
            if (counter1 == counter2) return true;
        }

        return false;
    }
};