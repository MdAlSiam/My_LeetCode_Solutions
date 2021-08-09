#include <bits/stdc++.h>
using namespace std;

class Solution {
    pair<int,int> par[501][510];
    int rank[501][501];

    pair<int,int> find_parent_and_compress(pair<int,int> a) {
        if(par[a.first][a.second] == a) return a;
        return par[a.first][a.second] = find_parent_and_compress(par[a.first][a.second]);
    }

    void make_friendship_and_kount_friends_in_circle(pair<int,int> a ,pair<int,int> b) {
        a = find_parent_and_compress(a);
        b = find_parent_and_compress(b);

        if(rank[a.first][a.second] > rank[b.first][b.second]) {
            par[b.first][b.second] = a;
            rank[a.first][a.second]++;
        } 
        else {
            par[a.first][a.second] = b;
            rank[b.first][b.second]++;
        }
    }

public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> tmp;
            tmp.clear();
            for (int j =0; j < m; j++) {
               tmp.push_back(0);
            }
            ans.push_back(tmp);
        }

        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                par[i][j] = {i,j};
                rank[i][j] = 1;
            }
        }

        // row 
        for (int i = 0; i < n; i++) {
            map<int, pair<int,int>> mp;
            for(int j = 0; j < m; j++) {
                if(mp.count(matrix[i][j])) {
                    make_friendship_and_kount_friends_in_circle({i,j}, mp[matrix[i][j]]);
                }
                else {
                    mp[matrix[i][j]]={i,j};
                }
            }
        }

        // col
        for (int j = 0; j < m; j++) {
            map<int, pair<int,int>> mp;
            for(int i = 0; i < n; i++) {
                if(mp.count(matrix[i][j])) {
                    make_friendship_and_kount_friends_in_circle({i,j}, mp[matrix[i][j]]);
                }
                else {
                    mp[matrix[i][j]]={i,j};
                }
            }
        }

        // make clusters
        vector<pair<int,int>> v[n][m];
        
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pair<int, int> x = find_parent_and_compress({i,j});
                v[x.first][x.second].push_back({i,j});
            }
        }

        map<int, vector<vector<pair<int,int>>>> mpp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j].size() == 0) continue;
                mpp[matrix[i][j]].push_back(v[i][j]);
            }
        }

        vector<int> ro;
        for (int i = 0; i < n; i++) ro.push_back(0);
        vector<int> col;
        for (int i = 0; i < m; i++) col.push_back(0);

        for (auto thing : mpp) {
            vector<vector<pair<int,int>>> rightThing = thing.second;

            for (vector<pair<int,int>> cluster : rightThing) {
                int maxi = 0;

                for (pair<int,int> a_pair : cluster) {
                    maxi = max(maxi, max(ro[a_pair.first], col[a_pair.second])+1);
                }

                for (pair<int,int> a_pair : cluster) {
                    ans[a_pair.first][a_pair.second] = maxi;
                    ro[a_pair.first] = max(ro[a_pair.first], maxi);
                    col[a_pair.second] = max(col[a_pair.second], maxi);
                }
            }
        }

        return ans;
    }
};

int main() {

}
