/*
* @Author: icher
* @Date:   2019-04-14 18:49:55
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:50:32
*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

示例 1:

输入: dividend = 10, divisor = 3
输出: 3
示例 2:

输入: dividend = 7, divisor = -3
输出: -2
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
         bool flag = false;
        int result = 0;
        unsigned udividend = 0;
        unsigned udivisor  = 0;

        flag = dividend > 0 xor divisor > 0;

        if (dividend == 0) {
            return 0;
        }

        udividend = dividend == -2147483648 ? 2147483648 : dividend > 0 ? dividend : -dividend;
        udivisor  = divisor == - 2147483648 ? 2147483648 : divisor > 0 ? divisor : - divisor;

       for (int i = 31; i >= 0 && udividend >= udivisor; --i) {
            if (udividend >> i >= udivisor) {
                result += 1 << i;
                udividend -= udivisor << i;
            }
        }

        if (result == -2147483648) {
            result = flag ? result : 2147483647;
        }
        else {
            result = flag ? -result : result;
        }

        return result;
    }
};
