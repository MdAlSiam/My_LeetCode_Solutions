class Solution:
    def removeStars(self, s: str) -> str:
        st = deque()

        for ch in s:
            if ch == '*':
                if len(st):
                    st.pop()
            else:
                st.append(ch)

        ans = ""
        for ch in st:
            ans += ch 
        
        return ans