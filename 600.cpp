#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int lastNum;
    int ans = 1;
    
    void dfs(int num, int lastBit) {
        if (num > lastNum) return;
        ans++;
        if (lastBit == 0) {
            dfs(2*num+1, 1);
        }
        dfs(2*num, 0);
    }
public:
    int findIntegers(int n) {
        lastNum = n;
        dfs(1, 1);
        return ans;
    }
};

int main() {

}