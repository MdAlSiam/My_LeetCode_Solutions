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
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        dsu = DSU(n)

        edgeList.sort(key=lambda x:x[2])
        q = [(l, u, v, i) for i, (u, v, l) in enumerate(queries)]
        q.sort()

        m = len(queries)
        ans = [False]*m
        edge_size = len(edgeList)
        edge_index = 0

        for q_limit, u, v, i in q:
            while edge_index < edge_size and edgeList[edge_index][2] < q_limit:
                dsu.add_friends(edgeList[edge_index][0], edgeList[edge_index][1])
                edge_index += 1
            ans[i] = bool(dsu.find_parent(u) == dsu.find_parent(v))

        return ans