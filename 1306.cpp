class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited;
        for (int a : arr) visited.push_back(false);
        stack<int> indices;
        indices.push(start);

        while (!indices.empty()) {
            int curr = indices.top();
            indices.pop();

            if (arr[curr] == 0) return true;

            int leftPos = curr-arr[curr];
            int rightPos = curr+arr[curr];

            if (leftPos >= 0 and !visited[leftPos]) indices.push(leftPos);
            if (rightPos < arr.size() and !visited[rightPos]) indices.push(rightPos);

            visited[curr] = true;
        }

        return false;
    }
};