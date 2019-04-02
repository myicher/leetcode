/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 



以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。

 



图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。

 

示例:

输入: [2,1,5,6,2,3]
输出: 10
 */

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
           int size  = heights.size();
        int result = 0;
        stack<int> record;
        
        if (size == 0) {
            return 0;
        }
        
        int left[size];
        int right[size];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for (int i = 0; i < size; ++i) {
            while (!record.empty() && heights[record.top()] >= heights[i]) {
                record.pop();
            }

            if (record.empty()) {
                left[i] = -1;
            }
            else {
                left[i] = record.top();
            }
            record.push(i);
        }

        while (!record.empty()) {
            record.pop();
        }

        for (int i = size - 1; i >= 0; --i) {
            while (!record.empty() && heights[record.top()] >= heights[i]) {
                record.pop();
            }

            if (record.empty()) {
                right[i] =  size;
            }
            else {
                right[i] = record.top();
            }

            result = max(result, heights[i] * (right[i] - left[i] - 1));
            record.push(i);
        }
        return result;
    }
};