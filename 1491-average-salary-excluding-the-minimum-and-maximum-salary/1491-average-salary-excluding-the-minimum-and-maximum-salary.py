class Solution:
    def average(self, salary: List[int]) -> float:
        total = 0
        mini = 10000000
        maxi = -1
        for sal in salary:
            total += sal
            mini = min(sal, mini)
            maxi = max(sal, maxi)
        return (total-mini-maxi)/(len(salary)-2)
            