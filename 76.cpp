/*
给定一个字符串 S 和一个字符串 T，请在 S 中找出包含 T 所有字母的最小子串。

示例：

输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：

如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
 */

class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> dict;
        unordered_map<char, int> statistics;
        int count = 0;
        int size1 = 0;
        int size2 = 0;
        int left  = 0;
        int right = 0;
        int maxIndex = 0;
        int minIndex = 0;
        bool flag = false;

        size1 = s.length();
        size2 = t.length();
        maxIndex = size1;

        for (int i = 0; i < size2; i++) {
            dict[t[i]]++;
        }

        while (right < size1 || count == size2) {
            if (count < size2 && right < size1) {
                if (statistics[s[right]] < dict[s[right]]) {
                    ++count;
                }
                statistics[s[right++]]++;
            }
            else {
                flag = true;
                if (statistics[s[left]] == dict[s[left]] && count == size2) {
                   if (right - left < maxIndex - minIndex) {
                       maxIndex = right;
                       minIndex = left;
                   }
                    --count;
                }
                --statistics[s[left++]];
            }
        }

        return flag ? s.substr(minIndex, maxIndex - minIndex) : "";
    }
};