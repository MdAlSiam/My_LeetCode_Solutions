public class Solution {
    public string DecodeString(string s) {
        Stack<int> st_times = new Stack<int>();
        Stack<StringBuilder> st_str = new Stack<StringBuilder>();

        int curr_num = 0;
        StringBuilder curr_str = new StringBuilder();

        for (int i = 0; i < s.Length; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                curr_num *= 10;
                curr_num += (int) (s[i]-'0');
            }
            else if (s[i] >= 'a' && s[i] <= 'z') {
                curr_str.Append(s[i]);
            }
            else if (s[i] == '[') {
                st_times.Push(curr_num);
                st_str.Push(curr_str);

                curr_num = 0;
                curr_str = new StringBuilder("");
                // curr_str.Clear();
            }
            else {
                StringBuilder prev = st_str.Peek();
                st_str.Pop();
                int times = st_times.Peek();
                st_times.Pop();

                StringBuilder new_strng = prev;
                while (times-- > 0) new_strng.Append(curr_str);

                curr_str = new_strng;
            }
        }

        return curr_str.ToString();
    }
}