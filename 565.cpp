#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;

    int ans;

    int* parent;
    int* rank;

    void initialise() {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find_parent(int node) {
        if (parent[node] != node) return parent[node] = find_parent(parent[node]);
        return node;
    }

    int make_friends(int node1, int node2) {
        int u = find_parent(node1);
        int v = find_parent(node2);

        if (u == v) return rank[u];

        parent[v] = u;
        rank[u] += rank[v];
        return rank[u];
    }

public:
    int arrayNesting(vector<int>& nums) {
        n = nums.size();

        initialise();

        ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, make_friends(i, nums[i]));
        }

        return ans;
    }
};

int main() {
    // LeetCode 565: Array nesting (DSU)
    
    vector<int> nums = {5,4,0,3,1,6,2};
    Solution s;
    cout << s.arrayNesting(nums) << endl;
}

