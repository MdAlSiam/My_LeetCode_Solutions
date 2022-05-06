class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> chars;
        stack<int> kounts;

        for (char ch : s) {
            if (chars.empty()) {
                chars.push(ch);
                kounts.push(1);
            }
            else if (ch != chars.top()) {
                chars.push(ch);
                kounts.push(1);
            }
            else {
                chars.push(ch);
                kounts.push(kounts.top()+1);

                if (kounts.top() == k) {
                    for (int i = 0; i < k; i++) {
                        chars.pop();
                        kounts.pop();
                    }
                }
            }
        }

        string ans = "";
        while (not chars.empty()) {
            ans += chars.top();
            chars.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};