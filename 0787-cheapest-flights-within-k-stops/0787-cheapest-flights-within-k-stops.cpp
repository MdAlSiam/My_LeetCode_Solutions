class Solution {
    #define ll long long int
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<ll, ll>>> adjList(n);

        for (vector<int> flight : flights) {
            adjList[flight[0]].push_back(make_pair(flight[1], flight[2]));
        }

        k++; // at most we can go to level k

        vector<ll> levelCost(n, 1000000000);
        queue<pair<ll, ll>> q;
        q.push({src, 0});
        levelCost[src] = 0;
        int level = 0;

        while (!q.empty() and level < k) {
        int sz = q.size();
        while (sz--) {
            ll curr = q.front().first;
            ll costTillHere = q.front().second;
            q.pop();

            for (pair<ll, ll> toGo : adjList[curr]) {                
                if (levelCost[toGo.first] > toGo.second+costTillHere) {
                    levelCost[toGo.first] = toGo.second+costTillHere;
                    q.push({toGo.first, levelCost[toGo.first]});
                }
            }
        }
        level++;
        }
        
        if (levelCost[dst] == 1000000000) return -1;
        return levelCost[dst];
    }
};