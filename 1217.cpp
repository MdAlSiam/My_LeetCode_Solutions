class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        sort(position.begin(), position.end());

        int ans = 200;

        for (int i = 0; i < position.size(); i++) {
            int ansHere = 0;
            for (int j = 0; j < position.size(); j++) {
                int cost = (abs(position[j]-position[i]))%2;
                ansHere += cost;
            }
            ans = min(ans, ansHere);
        }

        return ans;
    }
};