class SmallestInfiniteSet:
    missing_numbers = set()
    def __init__(self):
        self.missing_numbers.clear()

    def popSmallest(self) -> int:
        for i in range(1, 1000000):
            if i not in self.missing_numbers:
                self.missing_numbers.add(i)
                return i


    def addBack(self, num: int) -> None:
        if num in self.missing_numbers:
            self.missing_numbers.remove(num)
        


# Your SmallestInfiniteSet object will be instantiated and called as such:
# obj = SmallestInfiniteSet()
# param_1 = obj.popSmallest()
# obj.addBack(num)