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
            return False
        
        if self.ranks[u] > self.ranks[v]:
            self.parents[v] = u
            self.ranks[u] += self.ranks[v]
        else:
            self.parents[u] = v
            self.ranks[v] += self.ranks[u]

        return True


class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        edges.sort(reverse=True)

        alice_set = DSU(n+1)
        alice_cnt = 0
        bob_set = DSU(n+1)
        bob_cnt = 0
        remove_cnt = 0

        for type, u, v in edges:
            if type == 3:
                if alice_set.add_friends(u, v):
                    bob_set.add_friends(u, v)
                    alice_cnt += 1
                    bob_cnt += 1
                else:
                    remove_cnt += 1
            elif type == 2:
                if bob_set.add_friends(u, v):
                    bob_cnt += 1
                else:
                    remove_cnt += 1
            else:
                if alice_set.add_friends(u, v):
                    alice_cnt += 1
                else:
                    remove_cnt += 1

        return remove_cnt if alice_cnt == bob_cnt == n-1 else -1