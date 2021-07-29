#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> v[12];
    vector<string> answerVector;
    string given;

    int calculateValue(string strPart, int lo, int hi) {
        int ret = 0;
        for (int i = lo; i <= hi; i++) {
            ret *= 10;
            ret += strPart[i]-'0';
        }
        return ret;
    }

    void go(int initPos, int firstStopsAt, int secondStopsAt, int thirdStopsAt, int fourthStopsAt) {
        if (firstStopsAt == -1) {
            for (int i = 0; i < v[initPos].size(); i++) {
                go(v[initPos][i]+1, v[initPos][i], -1, -1, -1);
            }
        }
        else if (secondStopsAt == -1) {
            for (int i = 0; i < v[initPos].size(); i++) {
                go(v[initPos][i]+1, firstStopsAt, v[initPos][i], -1, -1);
            }
        }
        else if (thirdStopsAt == -1) {
            for (int i = 0; i < v[initPos].size(); i++) {
                go(v[initPos][i]+1, firstStopsAt, secondStopsAt, v[initPos][i], -1);
            }
        }
        else {
            for (int i = 0; i < v[initPos].size(); i++) {
                if (v[initPos][i] == given.size()-1) {
                    string found = "";
                    for (int jj = 0; jj <= firstStopsAt; jj++) {
                        found += given[jj];
                    }
                    found += ".";
                    for (int jj = firstStopsAt+1; jj <= secondStopsAt; jj++) {
                        found += given[jj];
                    }
                    found += ".";
                    for (int jj = secondStopsAt+1; jj <= thirdStopsAt; jj++) {
                        found += given[jj];
                    }
                    found += ".";
                    for (int jj = thirdStopsAt+1; jj <= v[initPos][i]; jj++) {
                        found += given[jj];
                    }

                    answerVector.push_back(found);

                    break;
                }
            }
        }
    }
    
public:
    vector<string> restoreIpAddresses(string s) {
        answerVector.clear();

        if (s.length() > 12) {
            return answerVector;
        }

        given = s;

        for (int i = 0; i < 12; i++) v[i].clear();

        for (int start = 0; start < s.size(); start++) {
            for (int stop = start; stop < 3+start; stop++) {
                int nLeadingZeros = 0;
                for (int j = start; j <= stop and stop > start; j++) {
                    if (s[j]-'0' != 0) break;
                    nLeadingZeros++;
                }
                if (calculateValue(s, start, stop) <= 255 and (not nLeadingZeros)) {
                    v[start].push_back(stop);
                }
            }
        }   

        go(0, -1, -1, -1, -1);

        return answerVector; 
    }
};

int main() {
    Solution s;
    // Call s
}