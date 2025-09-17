class Solution:
    def takeTwoStone(self, stones: List[int], k: int) -> List[int]:
        heapq._heapify_max(stones)
        
        res = []

        # s-cases
        if len(stones) == 2:
            res.append(heapq.heappop(stones))
            res.append(heapq.heappop(stones))
            return res

        # normal-cases
        while (len(stones) >= k and len(res) < 2):
            res.append(heapq.heappop(stones))
            heapq._heapify_max(stones)
        
        return res

    def lastStoneWeight(self, stones: List[int]) -> int:
        # s-cases
        if len(stones) < 2:
            return stones[0]

        while len(stones) >= 2:
            res = self.takeTwoStone(stones, 2)
            
            if len(res) < 2:
                break

            if res[0] != res[1]:
                y = res[0] - res[1]
                stones.append(y)

        if len(stones) == 1:
            return stones[0]
        else:
            return 0