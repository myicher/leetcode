/*
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int reach = 0;
        int reach_max = 0;
        int size = nums.size();

        if (size == 1) {
            return 0;
        }

        for (int i = 0; i < size; i++) {
            reach_max = max(i+nums[i], reach_max);
            if (reach_max >= size - 1) {
                ++step;
                break;
            }

            if (i == reach) {
                ++step;
                reach = reach_max;
            }
        }

        return step;
    }
};