#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Path {
        string start;
        vector<string> thePath;
        Path(string _start, vector<string> _thePath) {
            start = _start;
            thePath = _thePath;
        }
    };

    bool differsByOne(string str1, string str2) {
        int nDifferingLetter = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                nDifferingLetter++;
            }
        }
        return nDifferingLetter == 1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return {};
        }

        auto it = find(wordList.begin(), wordList.end(), beginWord);
        if (it != wordList.end()) {
            wordList.erase(it);
        }

        int maxLength = wordList.size()+2;

        vector<vector<string>> ans;

        queue<Path> q;
        q.push({beginWord, {beginWord}});
        map<string, bool> visited;

        while (!q.empty()) {
            string toBegin = q.front().start;
            vector<string> currPath = q.front().thePath;
            q.pop();

            if (toBegin == endWord and currPath.size() <= maxLength) {
                ans.push_back(currPath);
                maxLength = currPath.size();
            }

            visited[toBegin] = true;

            for (int i = 0; i < wordList.size(); i++) {
                if ((not visited.count(wordList[i])) and differsByOne(toBegin, wordList[i])) {
                    currPath.push_back(wordList[i]);
                    q.push({wordList[i], {currPath}});
                    currPath.pop_back();
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
}