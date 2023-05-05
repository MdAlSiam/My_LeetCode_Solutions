class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        d = {
            'a' : 0,
            'e' : 0,
            'i' : 0,
            'o' : 0,
            'u' : 0
        }

        curr_total = 0
        ans = 0

        # first segment
        for i in range(k):
            if s[i] in ['a', 'e', 'i', 'o', 'u']:
                d[s[i]] += 1
                curr_total += 1

        ans = max(ans, curr_total)

        for i in range(k, len(s)):
            if s[i-k] in ['a', 'e', 'i', 'o', 'u']:
                d[s[i-k]] -= 1
                curr_total -= 1
            if s[i] in ['a', 'e', 'i', 'o', 'u']:
                d[s[i]] += 1
                curr_total += 1
                ans = max(ans, curr_total)

        return ans