class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        ans.push_back({1});
        
        for (int i = 1; i < numRows; i++) {
            vector<int> t;
            t.push_back(ans[i-1][0]);
            
            for (int j = 1; j < ans[i-1].size(); j++) {
                t.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            
            int sz = ans[i-1].size();
            t.push_back(ans[i-1][sz-1]);
            
            ans.push_back(t);
        }
        
        return ans;
    }
};