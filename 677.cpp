#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class MapSum {
    struct node {
        int sum;
        bool endPoint;
        int endVal;
        node* child[26];

        node() {
            sum = 0;
            endPoint = false;
            endVal = 0;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

public:
    node* root;

    MapSum() {
        root = new node();
    }
    
    void insert(string key, int val) {
        node* curr = root;

        for (int i = 0; i < key.length(); i++) {
            if (curr->child[key[i]-'a'] == nullptr)  {
                curr->child[key[i]-'a'] = new node();
            }
            curr = curr->child[key[i]-'a'];
            curr->sum += val;
        }

        if (curr->endPoint == true) {
            int prevVal = curr->endVal;
            int toAdd = -prevVal+val;

            node* curr = root;

            for (int i = 0; i < key.length(); i++) {
                curr = curr->child[key[i]-'a'];
                curr->sum -= val;
                curr->sum += toAdd;
            }
        }

        curr->endPoint = true;
        curr->endVal = val;
    }
    
    int sum(string prefix) {
        node *curr = root;
        
        for (int i = 0; i < prefix.length(); i++) {
            if (curr->child[prefix[i]-'a'] == nullptr) {
                return 0;
            }
            curr = curr->child[prefix[i]-'a'];
        }

        return curr->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
    // Problem Link: https://leetcode.com/problems/map-sum-pairs/
}