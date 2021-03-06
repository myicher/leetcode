/*
* @Author: icher
* @Date:   2019-04-14 18:39:31
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:41:52
*
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且 n 的值至少为 2。



图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。

 

示例:

输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int left  = 0;
        int right = height.size() - 1;

        while (right - left > 0) {
            maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
            if (height[right] > height[left]) {
                ++left;
            }
            else {
                --right;
            }
        }

        return maxArea;
    }
};
