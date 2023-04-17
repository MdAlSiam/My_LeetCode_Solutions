class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        maxi = 0
        for candy in candies:
            maxi = max(maxi, candy)

        res = []
        for candy in candies:
            if candy+extraCandies >= maxi:
                res.append(True)
            else:
                res.append(False)

        return res