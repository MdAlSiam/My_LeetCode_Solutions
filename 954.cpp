#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (freq[arr[i]] and freq[2*arr[i]]) {
                freq[arr[i]]--;
                freq[2*arr[i]]--;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            if (freq[arr[i]]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    // Problem: LeetCode 954: Array of Doubled Pairs (Hashmap)
    // Problem Link: https://leetcode.com/problems/array-of-doubled-pairs/
}