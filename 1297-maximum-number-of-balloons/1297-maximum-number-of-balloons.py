class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        '''
        create a dictionary to keep tracks for each character in the string.
        notice for a balloon word, the dictionary will pretty much look like this:
        {
            'b': 1,
            'a': 1,
            'l': 2,
            'o': 2,
            'n': 1
        }
        but what if the word we want to check all are consists of one letter only? the logic is that:
        we can just find the minimum as the max number of that word we can make.
        so, we can just divide 'l' and 'o' by 2 to make all letter distributions the same.
        then, we can find the minimum of the number between key 'b', 'a', 'l', 'o', and 'n'.
        '''
        maps = {}
        
        for ch in text:
            if ch not in maps:
                maps[ch] = 1
            else:
                maps[ch] += 1
        
        if 'l' in maps: 
            maps['l'] = maps['l'] // 2
        else:
            return 0

        if 'o' in maps: 
            maps['o'] = maps['o'] // 2
        else:
            return 0
        
        sets = ('b', 'a', 'l', 'o', 'n')
        ans = 9999
        for ch in sets:
            if ch not in maps:
                return 0
            ans = min(ans, maps[ch])

        return ans