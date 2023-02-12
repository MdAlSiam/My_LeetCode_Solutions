class Solution {
    int n;
    int nSeats;
    long long int ans = 0;

    int dfs(vector<vector<int>>& adj_list, int dad, int son) {
        int subKount = 0;
        for (int i = 0; i < adj_list[son].size(); i++) {
            int grandson = adj_list[son][i];
            if (grandson == dad) continue;

            int subKountHere = dfs(adj_list, son, grandson);
            ans += (subKountHere+nSeats-1)/nSeats;
            subKount += subKountHere;
        }
        return 1+subKount;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size() + 1;
        nSeats = seats;

        vector<vector<int>> adj_list(n);
        for (vector<int> v: roads) {
            adj_list[v[0]].push_back(v[1]);
            adj_list[v[1]].push_back(v[0]);
        }

        dfs(adj_list, -1, 0);

        return ans;
    }
};