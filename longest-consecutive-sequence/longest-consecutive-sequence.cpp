class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> sett;

        for (int num : nums) {
            sett.insert(num);
        }

        int longestStreak = 0;

        for (int num : sett) {
            if (sett.find(num-1) == sett.end()) {
                int currNum = num;
                int currStreak = 1;

                while (sett.find(currNum+1) != sett.end()) {
                    currNum += 1;
                    currStreak += 1;
                }

                longestStreak = max(longestStreak, currStreak);
            }
        }

        return longestStreak;
    }
};