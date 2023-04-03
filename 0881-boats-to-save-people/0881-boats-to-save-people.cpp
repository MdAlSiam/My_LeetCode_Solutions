class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int lo = 0; 
        int hi = people.size()-1;

        int ans = 0;

        while (lo <= hi) {
            if (lo == hi) {
                ans++;
                break;
            }
            else if (people[lo]+people[hi] <= limit) {
                ans++;
                lo++;
                hi--;
            }
            else {
                ans++;
                hi--;
            }
        }

        return ans;
    }
};