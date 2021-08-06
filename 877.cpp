#include <bits/stdc++.h>
using namespace std;

class Solution {
    int dp[505][505];

    int go(int i, int j, vector<int>& piles) {
        if (i == j) return dp[i][j] = piles[i];
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = max(piles[i]+go(i+1, j, piles), piles[j]+go(i, j-1, piles));
    }
public:
    bool stoneGame(vector<int>& piles) {
        for (int i = 0; i <= piles.size()+1; i++) {
            for (int j = 0; j <= piles.size()+1; j++) {
                dp[i][j] = -1;
            }
        }

        return go(0, piles.size()-1, piles) > 0;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/stone-game/
}