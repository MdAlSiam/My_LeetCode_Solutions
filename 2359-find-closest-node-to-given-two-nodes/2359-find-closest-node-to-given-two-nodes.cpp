class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<vector<int>> adjList(n);
        for (int i = 0; i < edges.size(); i++) {
            int to = edges[i];
            if (to == -1) continue;
            adjList[i].push_back(to);
        }

        vector<pair<int, int>> distanceFromNodes(n, {-1, -1});

        // BFS for node1
        queue<int> q;
        distanceFromNodes[node1].first = 0;
        q.push(node1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < adjList[curr].size(); i++) {
                int toGo = adjList[curr][i];
                if (distanceFromNodes[toGo].first == -1) {
                    distanceFromNodes[toGo].first = distanceFromNodes[curr].first + 1;
                    q.push(toGo);
                }
            }
        }

        // BFS for node2
        distanceFromNodes[node2].second = 0;
        q.push(node2);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < adjList[curr].size(); i++) {
                int toGo = adjList[curr][i];
                if (distanceFromNodes[toGo].second == -1)  {
                    distanceFromNodes[toGo].second = distanceFromNodes[curr].second + 1;
                    q.push(toGo);
                }
            }
        }

        int ans = -1;
        int minMaxDistance = 10000000;

        for (int i = 0; i < distanceFromNodes.size(); i++) {
            if (distanceFromNodes[i].first == -1 or distanceFromNodes[i].second == -1) continue;
            if (max(distanceFromNodes[i].first, distanceFromNodes[i].second) < minMaxDistance) {
                minMaxDistance = max(distanceFromNodes[i].first, distanceFromNodes[i].second);
                ans = i;
            }
        }

        return ans;
    }
};