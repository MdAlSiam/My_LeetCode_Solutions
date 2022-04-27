class Solution {
    vector<int> adj_list[100005];
    bool seen[100005];
    vector<int> positions;
    vector<char> characters;
    string str;

    void dfs(int dad) {
        seen[dad] = true;
        positions.push_back(dad);
        characters.push_back(str[dad]);

        for (int i = 0; i < adj_list[dad].size(); i++) {
            int son = adj_list[dad][i];

            if (son == dad or seen[son]) continue;

            dfs(son);
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {

        str = s;

        // Make the graph from pairs
        for (int i = 0; i < 100005; i++) {
            adj_list[i].clear();
            seen[i] = false;
        }

        for (vector<int> aPair : pairs) {
            adj_list[aPair[0]].push_back(aPair[1]);
            adj_list[aPair[1]].push_back(aPair[0]);
        }

        // DFS from all (unseen) nodes to find the connected components
        //     And store the positions and characters
        //     Sort the positions and characters
        //     Place the characters accordingly

        for (int node = 0; node < str.length(); node++) {
            if (not seen[node]) {
                positions.clear();
                characters.clear();

                dfs(node);

                sort(positions.begin(), positions.end());
                sort(characters.begin(), characters.end());

                for (int i = 0; i < positions.size(); i++) {
                    str[positions[i]] = characters[i];
                }
            }
        }

        return str;
    }
};