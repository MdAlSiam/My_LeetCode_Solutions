class WordDictionary {
    unordered_map<int, vector<string>> words;

    bool isEqual(string str1, string str2) {
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] == '.') continue;
            if (str1[i] != str2[i]) return false;
        }
        return true;
    }
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        for (string str2 : words[word.size()]) {
            if (isEqual(word, str2)) {
                return true;
            }
        }
        return false;
    }
};