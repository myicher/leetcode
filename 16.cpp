/*
* @Author: icher
* @Date:   2019-04-14 18:43:25
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:43:52
*
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
                int result = 0;
        int left   = 0;
        int right  = 0;
        int compare = 0;

        sort(nums.begin(), nums.end());
        result = nums[0] + nums[1] + nums[2] - target;
        for (int i = 0; i < nums.size(); ++i) {
            compare = target - nums[i];
            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                result = abs(result) > abs(nums[left] + nums[right] - compare) ? nums[left] + nums[right] - compare : result;
                if (nums[left] + nums[right] - compare == 0) {
                    return  result + target;
                }
                else if (nums[left] + nums[right] - compare > 0) {
                    --right;
                }
                else {
                    ++left;
                }
            }
        }
        return result + target;
    }
};
