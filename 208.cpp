class Trie {
    struct node {
        bool endsHere;
        node* child[26];

        node() {
            endsHere = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    node* root;
public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->child[word[i]-'a'] == nullptr) {
                curr->child[word[i]-'a'] = new node();
            }

            curr = curr->child[word[i]-'a'];
        }

        curr->endsHere = true;
    }
    
    bool search(string word) {
        node* curr = root;

        for (int i = 0; i < word.size(); i++) {
            if (curr->child[word[i]-'a'] == nullptr) return false;
            curr = curr->child[word[i]-'a'];
        }

        return curr->endsHere;
    }
    
    bool startsWith(string prefix) {
        node* curr = root;
        
        for (int i = 0; i < prefix.size(); i++) {
            if (curr->child[prefix[i]-'a'] == nullptr) return false;
            curr = curr->child[prefix[i]-'a'];
        }

        return true;
    }
};