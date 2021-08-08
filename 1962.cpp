#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < piles.size(); i++) {
            pq.push(piles[i]);
        }

        while (k--) {
            int top = pq.top();
            pq.pop();
            pq.push((top+1)/2);
        }

        int ans = 0;

        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }

        return ans;
    }
};

int main() {
    // Problem link: https://leetcode.com/problems/remove-stones-to-minimize-the-total/
}