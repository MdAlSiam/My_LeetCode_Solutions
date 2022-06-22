class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums) {
            if (pq.size() < k) {
                pq.push(num);
                continue;
            }

            if (num <= pq.top()) {
                continue;
            }

            pq.pop();
            pq.push(num);
        }

        return pq.top();
    }
};