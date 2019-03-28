/*
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int res    = 0;
        int index  = 0;
        int start  = 0;
        stack<int> stBracket;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stBracket.push(i);
            }
            else {
                if (stBracket.empty()) {
                    start = i+1;
                }
                else {
                    stBracket.pop();
                    if (stBracket.empty()) {
                        res = max(res, i - start + 1);
                    } else {
                        index = stBracket.top();
                        res = max(i - index, res);
                    }
                }
            }
        }

        printf("%d \n", res);
        return res;
    }
};

