class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int, int> firstSeen;
        firstSeen[0] = -1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) sum--;
            else sum++;

            if (firstSeen.count(sum)) {
                ans = max(ans, i-firstSeen[sum]);
            }
            else {
                firstSeen[sum] = i;
            }
        }

        return ans;
    }
};