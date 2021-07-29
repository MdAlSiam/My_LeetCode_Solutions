#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ret = {1};
        while (ret.size() < n) {
            vector<int> temp;
            temp.clear();
            for (int element : ret) if (2*element-1 <= n) temp.push_back(2*element-1);
            for (int element : ret) if (2*element <= n) temp.push_back(2*element);
            ret = temp;
        }
        return ret;
    }
};

int main() {
    // Too weired but interesting pattern
    // Call whatever it takes
    // Or run here: https://leetcode.com/problems/beautiful-array/
}