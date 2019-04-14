/*
* @Author: icher
* @Date:   2019-04-14 18:25:12
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:32:12
*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =  0;
        int right = 0;
        int maxlen = 0;
        int length = s.length();

        while (right < length) {
            int i = left;
            for (; i < right; ++i) {
                if (s[i] == s[right]) {
                    maxlen = max(maxlen, right - left);
                    left = i+1;
                    break;
                }
                
            }
            if (i == right) {
                maxlen = max(maxlen, right - left + 1);
            }

            ++right;
        }

        return maxlen;
    }
};