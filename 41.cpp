/*
给定一个未排序的整数数组，找出其中没有出现的最小的正整数。

示例 1:

输入: [1,2,0]
输出: 3
示例 2:

输入: [3,4,-1,1]
输出: 2
示例 3:

输入: [7,8,9,11,12]
输出: 1
说明:

你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
 */

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size  = 0;
        size = nums.size();
        if (size == 0) {
            return 1;
        }
        bool sign[size];
        memset(sign, 0, sizeof(sign));
        for (int i = 0; i < size; i++) {
            if (nums[i] < size) {
                sign[nums[i] - 1]  = true;
            }
        }

        for (int i = 0; i < size; i++) {
            if (sign[i] == false) {
                return i+1;
            }
        }

        return size+1;
    }
};