class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int num : stones) {
            pq.push(num);
        }

        while(pq.size() > 1) {
            int max_num = pq.top();
            pq.pop();
            int second_max_num = pq.top();
            pq.pop();

            pq.push(max_num-second_max_num);
        }

        if (pq.empty()) return 0;
        return pq.top();
    }
};