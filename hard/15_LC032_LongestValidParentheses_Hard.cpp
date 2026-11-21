// Problem 32: Longest Valid Parentheses
// Difficulty: Hard

#include <algorithm>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1); // Base index before the start of the current valid substring
        int maxLen = 0;

        for (int i = 0; i < static_cast<int>(s.size()); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i); // Unmatched ')' becomes the new base index
                } else {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};
