class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        vector<int> flippings;
        flippings.clear();
        flippings.push_back(1);

        for (int i = 1; i < arr.size(); i++) {
            int diff = arr[i]-arr[i-1];
            if (diff < 0) flippings.push_back(0);
            else if (diff == 0) flippings.push_back(-1);
            else flippings.push_back(1);
        }

        int ans = 1;
        int maxSoFar = 1;

        for (int i = 1; i < flippings.size(); i++) {
            if (flippings[i] == -1) {
                ans = max(ans, maxSoFar);
                maxSoFar = 1;
            }
            else if (i > 0 and flippings[i] != flippings[i-1]) {
                maxSoFar++;
                ans = max(ans, maxSoFar);
            }
            else {
                
                ans = max(ans, maxSoFar);
                maxSoFar = 2;
            }
        }
        ans = max(ans, maxSoFar);

        return ans;
    }
};