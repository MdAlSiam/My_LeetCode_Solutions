class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        }

        priority_queue<int> pq;

        long long int sum = 0;

        for (int num : target) {
            sum += num;
            pq.push(num);
        }

        while (pq.top() != 1) {
            int curr = pq.top();
            pq.pop();

            if (sum-curr == 1) return true;

            int x = curr % (sum-curr);
            if (x < 1 or x == curr) return false;

            sum = sum - curr + x;
            pq.push(x);
        }

        return true;
    }
};