// Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int nodesAddable = 1;
        stringstream ss(preorder);
        string str;
        while (getline(ss, str, ',')) {
            nodesAddable--;
            if (nodesAddable < 0) return false;
            if (str != "#") nodesAddable += 2;
        }
        return nodesAddable == 0;
    }
};