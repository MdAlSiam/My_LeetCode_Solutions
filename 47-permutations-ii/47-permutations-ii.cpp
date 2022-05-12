class Solution {
    vector<vector<int>> ans;

    void printNums(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            printf(i == nums.size()-1 ? "%d\n" : "%d ", nums[i]);
        }
    }

    void go(int position, vector<int>& nums) {
        
        if (position >= nums.size()) {
            ans.push_back(nums);
            return;
        }

        set<int> st;

        for (int i = position; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) continue;
            st.insert(nums[i]);
            
            swap(nums[position], nums[i]); 
            go(position+1, nums);
            swap(nums[position], nums[i]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        go(0, nums);
        return ans;
    }
};