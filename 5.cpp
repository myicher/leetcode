/*
* @Author: icher
* @Date:   2019-04-14 18:33:09
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:36:14
*
* 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end   = 0;
        int left  = 0;
        int right = 0;
        
           if (s.length() == 0) {
            return "";
        }

        for (int i = 0; i < s.length(); ++i) {
            left = i;
            right = i;
            while (right < s.length() && s[i] == s[right+1]) {
                ++right;
            }

             while (left > 0 && right < s.length() - 1 && s[left-1] == s[right+1]) {
                --left;
                ++right;
            };
            if (right - left >= end - start) {
                start = left;
                end   = right;
            }
        }

        return s.substr(start, end - start + 1);
    }
};

