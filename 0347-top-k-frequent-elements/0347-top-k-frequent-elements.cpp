class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counts;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> min_heap;

        for (int num : nums) counts[num]++;

        for (auto &element : counts) {
            min_heap.push({element.second, element.first});

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        vector<int> ans;

        while (min_heap.size()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }

        return ans;
    }
};