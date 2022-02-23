class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int kount = 0, res = 0;

        for (int num : nums) {
            if (kount == 0) {
                res = num;
            }

            if (num == res) {
                kount++;
            }
            else {
                kount--;
            }
        }

        return res;
    }
};