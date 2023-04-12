class Solution:
    def simplifyPath(self, path: str) -> str:
        files = path.split('/')
        accepted = deque()
        for file in files:
            if len(file):
                if file == "..":
                    if len(accepted):
                        accepted.pop()
                elif file == "." or file == "..":
                    pass
                else:
                    accepted.append(file)

        ans = ""
        for file in accepted:
            ans += '/'+file

        return ans if len(ans) else '/'