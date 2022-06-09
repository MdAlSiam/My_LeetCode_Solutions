class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int, int> mp;

        for (int i = 0; i < numbers.size(); i++) {
            int num = numbers[i];
            int req = target-num;

            if (mp.count(req)) {
                return {mp[req]+1, i+1};
            }

            mp[num] = i;
        }
        
        return {1, 2};
    }
};