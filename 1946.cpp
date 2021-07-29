#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        bool started = false;
        for (int i = 0; i < num.size(); i++) {
            if ((not started) and change[num[i]-'0'] > num[i]-'0')  started = true;
            if (started and change[num[i]-'0'] < num[i]-'0') break;

            if (started) {
                num[i] = change[num[i]-'0']+'0';
            }
        }
        return num;
    }
};

int main() {
    // Instantiate and call whatever it takes
    // Or run here: https://leetcode.com/problems/largest-number-after-mutating-substring/
}