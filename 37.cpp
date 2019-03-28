/*
编写一个程序，通过已填充的空格来解决数独问题。

一个数独的解法需遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
空白格用 '.' 表示。



一个数独。



答案被标成红色。

Note:

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
 */

class Solution {
public:
    bool dfs(vector<vector<char>>&board, vector<vector<int>>&row, vector<vector<int>>&col, vector<vector<int>>&block)
    {
        int nRow = 0;
        int nCol = 0;
        for (; nRow < 9; nRow++) {
            for (nCol = 0; nCol < 9; nCol++) {
                if (board[nRow][nCol] == '.') {
                    break;
                }
            }
            if (nCol != 9) {
                break;
            }
        }

        if (nRow == 9 && nCol == 9) {
            return true;
        }

        for (int i = 1; i <= 9; i++ ) {
            if (row[nRow][i] == 0 && col[nCol][i] == 0 && block[nRow/3*3+nCol/3][i] == 0) {
                board[nRow][nCol] = i + '0';
                row[nRow][i] = 1;
                col[nCol][i] = 1;
                block[nRow/3*3+nCol/3][i] = 1;
                if (dfs(board, row, col, block)) {
                    return true;
                }
                else {
                    board[nRow][nCol] = '.';
                    row[nRow][i] = 0;
                    col[nCol][i] = 0;
                    block[nRow/3*3+nCol/3][i] = 0;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int> > row(9, vector<int>(10));
        vector<vector<int> > col(9, vector<int>(10));
        vector<vector<int> > block(9, vector<int>(10));
        int num = 0;

        //  初始化行列块数据
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    num = board[i][j] - '0';
                    row[i][num] = 1;
                    col[j][num] = 1;
                    block[i/3*3+j/3][num] = 1;
                }
            }
        }

        dfs(board, row, col, block);
    }
};