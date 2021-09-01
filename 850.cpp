// Link: https://leetcode.com/problems/rectangle-area-ii/

class Solution {
public:
    long long int mod = 1000000007;

    struct vertical_line {
        long long int x;
        long long int type;
        long long int y1;
        long long int y2;
    };

    vertical_line* ara;

    void init_lines(long long int size) {
        ara = new vertical_line[3*size];
    }

    static bool compare(vertical_line v1, vertical_line v2) {
        return v1.x < v2.x;
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        init_lines(rectangles.size());

        long long int index = 0;

        for (long long int i = 0; i < rectangles.size(); i++) {
            long long int x1 = (long long int) rectangles[i][0];
            long long int y1 = (long long int) rectangles[i][1];
            long long int x2 = (long long int) rectangles[i][2];
            long long int y2 = (long long int) rectangles[i][3];

            ara[index].x = x1;
            ara[index].type = 0;
            ara[index].y1 = y1;
            ara[index].y2 = y2;
            index++;

            ara[index].x = x2;
            ara[index].type = 1;
            ara[index].y1 = y1;
            ara[index].y2 = y2;
            index++;
        }

        sort(ara, ara+index, compare);

        multiset<pair<long long int, long long int>> ys;
        ys.clear();

        long long int prev_x;
        long long int ans = 0;

        for (long long int i = 0; i < index; i++) {
            if (ys.size()) {
                long long int totalHeightHere = 0;

                long long int startVal = -1;
                long long int stopVal = -1;

                for (pair<long long int, long long int> ypair : ys) {

                    if (stopVal < ypair.first) {
                        // a new segment
                        totalHeightHere += (stopVal-startVal);
                        startVal = ypair.first;
                        stopVal = ypair.second;
                    }
                    else {
                        stopVal = max(stopVal, ypair.second);
                    }
                }
                totalHeightHere += (stopVal-startVal);

                long long int addhere = (((ara[i].x-prev_x)%mod)*(totalHeightHere%mod))%mod;
                ans = ((ans%mod)+(addhere%mod))%mod;
            }

            if (ara[i].type == 0) {
                ys.insert({ara[i].y1, ara[i].y2});
            }
            else {
                ys.erase(ys.find({ara[i].y1, ara[i].y2}));
            }

            prev_x = ara[i].x;
        }

        return (int) ans%mod;
    }
};