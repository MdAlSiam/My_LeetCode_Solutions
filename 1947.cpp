#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int table[15][15];

    bool taken[15];

    int n;

    void initialiseTaken() {
        for (int i = 0; i < 15; i++) {
            taken[i] = false;
        }
    }

    int go(int std_no, int sum) {
        if (std_no >= n) {
            return sum;
        }
        int ret = 0;
        for (int j = 0; j < n; j++) {
            if (not taken[j]) {
                taken[j] = true;
                int retHere = go(std_no+1, sum+table[std_no][j]);
                ret = max(ret, retHere);
                taken[j] = false;
            }
        }
        return ret;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        
        for (int i = 0; i < students.size(); i++) {
            for (int j = 0; j < mentors.size(); j++) {

                // Compatibility Score

                int cs = 0;
                for (int index = 0; index < students[i].size(); index++) {
                    if (students[i][index] == mentors[j][index]) {
                        cs++;
                    }
                }

                table[i][j] = cs;

            }
        }
        
        /*
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << table[i][j] << " ";
            }
            cout << " !!" << endl;
        }
        */

        n = students.size();

        initialiseTaken();

        int ans = go(0, 0);

        return ans;
    }
};

int main() {
    // Instantiate and call whatever it takes
    // Or run here: 
}