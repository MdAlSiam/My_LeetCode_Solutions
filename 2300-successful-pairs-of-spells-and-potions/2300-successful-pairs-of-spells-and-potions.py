class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        ans = [0 for i in range(len(spells))]

        potions.sort()

        for i, spell in enumerate(spells):
            minimum = (success+spell-1)//spell
            # minimum = math.ceil(success/spell)

            start = bisect.bisect_left(potions, minimum)

            ans[i] = len(potions)-start

        return ans