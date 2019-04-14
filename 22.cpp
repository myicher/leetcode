/*
* @Author: icher
* @Date:   2019-04-14 18:47:07
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:47:53
*
给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。

例如，给出 n = 3，生成结果为：

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
     void generate(vector<string> &result, string anwser, int lCounter, int rCounter, int n) {
        if (lCounter == n && rCounter == n) {
            result.push_back(anwser);
            return;
        }

        if (lCounter > n || rCounter > n) {
            return;
        }

        if (lCounter >= rCounter) {
            generate(result, anwser+"(", lCounter + 1, rCounter, n);
            generate(result, anwser+")", lCounter, rCounter + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "(", 1, 0, n);

        return result;
    }
};
