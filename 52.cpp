/*
n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。



上图为 8 皇后问题的一种解法。

给定一个整数 n，返回 n 皇后不同的解决方案的数量。

示例:

输入: 4
输出: 2
解释: 4 皇后问题存在如下两个不同的解法。
[
 [".Q..",  // 解法 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // 解法 2
  "Q...",
  "...Q",
  ".Q.."]
]
 */

class Solution {
public:
    void queenDFS(int &result, vector<int> &row, vector<int> &col, vector<int> &cross, vector<int> &backCross, int num)
    {
        if (num == row.size()) {
            ++result;
            return;
        }

        for (int i = 0; i < row.size(); i++) {
            if (row[num] == -1 && col[i] == 0 && cross[i + num] == 0 && backCross[row.size() - 1 - num + i] == 0) {
                row[num] = i;
                col[i]   = 1;
                cross[i + num] = 1;
                backCross[row.size() - 1 - num + i] = 1;
                queenDFS(result, row, col, cross, backCross, num+1);
                row[num] = -1;
                col[i]   = 0;
                cross[i + num] = 0;
                backCross[row.size() - 1 - num + i] = 0;
            }
        }
    }
   
        
    }
    
    int totalNQueens(int n) {
        int result = 0;
        vector<int> row(n, -1);
        vector<int> col(n, 0);
        vector<int> cross(2*n - 1, 0);
        vector<int> backCross(2*n - 1, 0);
        queenDFS(result, row, col, cross, backCross, 0);
        return result;
    }
};