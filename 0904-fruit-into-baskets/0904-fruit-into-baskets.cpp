class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;

        int currStreak = 0;
        int lastNumStreak = 0;

        int prevNum = -1;
        int currNum = -1;

        for (int i = 0; i < fruits.size(); i++) {
            if (fruits[i] != currNum) {
                if (fruits[i] != prevNum) {
                    currStreak = lastNumStreak+1;
                }
                else {
                    currStreak++;
                }

                lastNumStreak = 1;
                
                prevNum = currNum;
                currNum = fruits[i];

                ans = max(ans, currStreak);
                continue;
            }

            currStreak++;
            lastNumStreak++;
            ans = max(ans, currStreak);
        }

        return ans;
    }
};