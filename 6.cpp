/*
* @Author: icher
* @Date:   2019-04-14 18:36:40
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:37:14
*
将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

L   C   I   R
E T O E S I I G
E   D   H   N
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
示例 1:

输入: s = "LEETCODEISHIRING", numRows = 3
输出: "LCIRETOESIIGEDHN"
示例 2:

输入: s = "LEETCODEISHIRING", numRows = 4
输出: "LDREOEIIECIHNTSG"
解释:

L     D     R
E   O E   I I
E C   I H   N
T     S     G
*/

class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.length();
        bool direct = 0;
        int rowNum = 0;
        string result("");
        vector<string> vecString(numRows);
        
        if (numRows == 1 || numRows == 0 || size == 0) {
            return s;
        }

        for (int i = 0; i < s.length(); ++ i) {
            if (i % (numRows - 1) == 0) {
                direct = 1 xor direct;
            }

            if (direct == 1) {
                rowNum = i % (numRows - 1);
                vecString[rowNum] += s[i];
            }
            else {
                rowNum = numRows - 1 - i % (numRows - 1);
                vecString[rowNum] += s[i];
            }
        }
        for (int i = 0; i < numRows; ++i) {
            result += vecString[i];
        }

        return result;
    }
};
