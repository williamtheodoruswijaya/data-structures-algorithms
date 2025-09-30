class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // edge-case:
        if (p.size() > s.size()) return vector<int>();
        
        vector<int> maps1(27, 0);
        vector<int> maps2(27, 0);

        int left = 0;
        vector<int> res;
        // step 1: get maps on p as well as expanding the first window
        for (int right = 0; right < p.size(); right++) {
            int idx1 = s[right] - 'a';
            int idx2 = p[right] - 'a';

            maps1[idx1]++;
            maps2[idx2]++;
        }

        // step 2: if we accidentally meet the first anagram while expanding, add it
        if (maps1 == maps2) res.push_back(0);

        // step 3: slide the window
        for (int right = p.size(); right < s.size(); right++) {
            
            // expand on the go
            int idx = s[right] - 'a';
            maps1[idx]++;

            // shrink if length of the window > p.size()
            if (right - left + 1 > p.size()) {
                int idx = s[left] - 'a';
                maps1[idx]--;
                left++;
            }

            // check if maps1 == maps2
            if (maps1 == maps2) {
                res.push_back(left);
            }
        }

        return res;
    }
};