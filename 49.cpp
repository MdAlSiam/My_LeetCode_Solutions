#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string now = strs[i];
            sort(now.begin(), now.end());
            mp[now].push_back(strs[i]);
        }

        for (auto key : mp) {
            ans.push_back(key.second);
        }
        return ans;
    }
};

int main() {
    // LeetCode 49: Group Anagrams
    // Problem Link: https://leetcode.com/problems/group-anagrams/
}