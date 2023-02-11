class Solution {
    vector<vector<int>> ans;
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // make the adjacency list
        vector<vector<pair<int, int>>> adjList(n);
        for (vector<int> edge : redEdges) {
            adjList[edge[0]].push_back({edge[1], 0});
        }
        for (vector<int> edge : blueEdges) {
            adjList[edge[0]].push_back({edge[1], 1});
        }

        // flood up the answer with -1
        for (int i = 0; i < n; i++) {
            ans.push_back({-1, -1});
        }

        // bfs
        queue<pair<int, int>> q;
        q.push({0, 0});
        ans[0][0] = 0;
        ans[0][1] = 0;

        while (!q.empty()) {
            int currNode = q.front().first;
            int currColor = q.front().second;
            q.pop();

            for (int i = 0; i < adjList[currNode].size(); i++) {
                int nextNode = adjList[currNode][i].first;
                int nextColor = adjList[currNode][i].second;

                if (currColor == nextColor and currNode != 0) continue;

                if (ans[nextNode][nextColor] == -1) {
                    ans[nextNode][nextColor] = ans[currNode][currColor] + 1;
                    q.push({nextNode, nextColor});
                }
            }
        }

        vector<int> finalAns;
        for (vector<int> anAns : ans) {
            if (anAns[0] == -1 and anAns[1] == -1) finalAns.push_back(-1);
            else if (anAns[0] == -1) finalAns.push_back(anAns[1]);
            else if (anAns[1] == -1) finalAns.push_back(anAns[0]);
            else finalAns.push_back(min(anAns[0], anAns[1]));
        }
        return finalAns;
    }
};