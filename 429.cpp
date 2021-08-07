#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return ans;
        Node* curr = root;
        queue<Node*> q;
        vector<int> temp;
        q.push(curr);
        q.push(nullptr);
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node != nullptr) {
                temp.push_back(node->val);
                for (Node* child : node->children) {
                    q.push(child);
                }
            }
            else {
                if (!q.empty()) {
                    ans.push_back(temp);
                    temp.clear();
                    q.push(nullptr);
                }
            }
        }
        if (temp.size()) ans.push_back(temp);
        temp.clear();

        return ans;
    }
};

int main() {
    // Problem Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
} 