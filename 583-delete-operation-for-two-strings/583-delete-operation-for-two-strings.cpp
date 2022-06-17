class Solution {
public:
    int minDistance(string word1, string word2) {
        word1 = "#"+word1;
        word2 = '#'+word2;

        int tab[word1.length()][word2.length()];

        for (int i = 0; i < word1.length(); i++) {
            for (int j = 0; j < word2.length(); j++) {
                if (i == 0 or j == 0) tab[i][j] = 0;
                else if (word1[i] == word2[j]) tab[i][j] = tab[i-1][j-1]+1;
                else tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
            }
        }

        cout << ">> " << tab[word1.length()-1][word2.length()-1] << endl;

        return word1.length()+word2.length()-2*tab[word1.length()-1][word2.length()-1]-2;
    }
};