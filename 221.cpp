class Solution {
    int findMaxAreaHistoram(vector<int> heights) {
        heights.push_back(0);
        
        stack<int> indices;

        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            if (indices.empty()) {
                indices.push(i);
                continue;
            }

            while (!indices.empty() and heights[i] < heights[indices.top()]) {
                int width = heights[indices.top()];
                indices.pop();

                int length = 0;
                if (indices.empty()) length = i;
                else length = i-indices.top()-1;

                maxArea = max(maxArea, min(length, width)*min(length, width));
            }

            indices.push(i);
        }

        return maxArea;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<int> heights;
        for (int i = 0; i < matrix[0].size(); i++) { 
            heights.push_back(0);
        }

        int maxSqArea = 0;

        for (vector<char> row : matrix) {
            for (int i = 0; i < row.size(); i++) {
                if (row[i] == '1') heights[i]++;
                else heights[i] = 0;
            }

            int maxSqAreaTillThisRow = findMaxAreaHistoram(heights);

            maxSqArea = max(maxSqArea, maxSqAreaTillThisRow);
        }

        return maxSqArea;
    }
};