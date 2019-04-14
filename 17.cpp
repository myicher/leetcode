/*
* @Author: icher
* @Date:   2019-04-14 18:44:24
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:52:52
*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。



示例:

输入："23"
输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
     void letterBy(map<int, string> &dict, int index, string greedStr,string digits, vector<string> &result) {
        if (index == digits.length()) {
            result.push_back(greedStr);
            return;
        }

        int tmp = digits[index] - '0';
        for (int i = 0; i < dict[tmp].size(); ++i) {
            greedStr += dict[tmp][i];
            letterBy(dict, index+1, greedStr, digits, result);
            greedStr.erase(greedStr.length() - 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        int num = 0;
        map<int, string> dict;
        vector<string> result;
        string inchar[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for (int i = 2; i <= 9; ++i) {
            dict[i] = inchar[i - 2];
        }
        
        if (digits.length() > 0)
        {
            letterBy(dict, 0, "", digits, result);
        }
        return result;
    }
};
