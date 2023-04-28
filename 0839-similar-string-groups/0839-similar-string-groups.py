class DSU:
    def __init__(self, n):
        self.parents = list(range(n))
        self.ranks = [1]*n
    
    def find_parent(self, node):
        if self.parents[node] == node:
            return node
        self.parents[node] = self.find_parent(self.parents[node])
        return self.parents[node]
    
    def add_friends(self, node1, node2):
        u = self.find_parent(node1)
        v = self.find_parent(node2)

        if u == v:
            return
        
        if self.ranks[u] > self.ranks[v]:
            self.parents[v] = u
            self.ranks[u] += self.ranks[v]
        else:
            self.parents[u] = v
            self.ranks[v] += self.ranks[u]


class Solution:
    def numSimilarGroups(self, strs: List[str]) -> int:
        dsu = DSU(len(strs))

        for i in range(len(strs)):
            for j in range(i, len(strs)):
                diff = 0
                for k in range(len(strs[0])):
                    if strs[i][k] != strs[j][k]:
                        diff += 1
                    if diff > 2:
                        break
                if diff <= 2:
                    dsu.add_friends(i, j)

        for i in range(len(strs)):
            dsu.find_parent(i)

        return len(set(dsu.parents))