#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0;
        map<int, int> mp;

        for (int num3 : nums3) {
            for (int num4 : nums4) {
                mp[num3+num4]++;
            }
        }

        for (int num1 : nums1) {
            for (int num2 : nums2) {
                ans += mp[-(num1+num2)];
            }
        }

        return ans;
    }
};

int main() {

}