#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        s = '#'+s;
        int nZerosTillHere[s.size()];

        nZerosTillHere[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            nZerosTillHere[i] = nZerosTillHere[i-1]+(s[i]=='0'?1:0);
        }

        int ans = 1000000;

        for (int i = 0; i < s.size(); i++) {
            int ansHere = i-nZerosTillHere[i]+nZerosTillHere[s.size()-1]-nZerosTillHere[i];
            // cout << "Index: " << i << " Ans= " << ansHere << endl;
            ans = min(ans, ansHere);
        }

        return ans;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/flip-string-to-monotone-increasing/
}