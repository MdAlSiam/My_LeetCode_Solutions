class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int, int> mp; // itemNo->index
        int index = 0;

        for (vector<int> v : items1) {
            ans.push_back(v);
            mp[v[0]] = index++;
        }

        for (vector<int> v : items2) {
            if (mp.count(v[0])) {
                ans[mp[v[0]]][1] += v[1];
            }
            else {
                ans.push_back(v);
            }
        }

        sort(ans.begin(), ans.end(),
            [] (const auto& a, const auto& b) {
                return a[0] < b[0];
            }
        );

        return ans;
    }
};