# https://leetcode.com/problems/decode-string/

class Solution:
    def decodeString(self, s: str) -> str:
        st = []
        currNum = 0
        currString = ""

        for ch in s:
            if ch == '[':
                st.append(currString)
                st.append(currNum)
                currNum = 0
                currString = ""
            elif ch == ']':
                times = st.pop()
                prevString = st.pop()
                currString = prevString+times*currString
            elif ch.isdigit():
                currNum = currNum*10+int(ch)
            else:
                currString += ch

        return currString
            