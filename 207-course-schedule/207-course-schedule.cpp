class Solution {
    int n;

    vector<int>* adj_list;
    bool* visited;
    bool* seenThisWay;
    bool hasCycle;

    void init() {
        adj_list = new vector<int>[n];
        visited = new bool[n];
        seenThisWay = new bool[n];
        for (int i = 0; i < n; i++) visited[i] = false;
        for (int i = 0; i < n; i++) seenThisWay[i] = false;
        hasCycle = false;
    }

    void dfs(int curr) {
        visited[curr] = true;
        seenThisWay[curr] = true;

        for (int kid : adj_list[curr]) {
            if (not visited[kid]) dfs(kid);
            else if (seenThisWay[kid]) {hasCycle = true; return;}
        }

        seenThisWay[curr] = false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        n = numCourses;
        init();

        for (vector<int> prerequisite : prerequisites) {
            adj_list[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < n; i++) {
            if (not visited[i]) dfs(i);
            if (hasCycle) return false;
        }

        return true;
    }
};