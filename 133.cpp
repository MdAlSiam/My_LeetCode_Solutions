class Solution {
    Node* dfs(Node* curr, unordered_map<Node*, Node*>& mp) {
        Node* clone = new Node(curr->val);
        mp[curr] = clone;
        vector<Node*> neighbors;

        for (auto adj_node : curr->neighbors) {
            if (mp.count(adj_node)) {
                neighbors.push_back(mp[adj_node]);
            }
            else {
                neighbors.push_back(dfs(adj_node, mp));
            }
        }

        clone->neighbors = neighbors;

        return clone;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        if (node == nullptr) {
            return nullptr;
        }

        if (node->neighbors.size() == 0) {
            return new Node(node->val);
        }

        return dfs(node, mp);
    }
};