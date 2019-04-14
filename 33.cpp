/*
* @Author: icher
* @Date:   2019-04-14 18:25:59
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:26:51
*
* 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是 O(log n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int mid  = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid]) {
                return  mid;
            }

            if (nums[left] > nums[right]) {
                if (nums[left] <= nums[mid]) {
                    if (target < nums[mid] && target >= nums[left]) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                else {
                    if (target <= nums[right] && target > nums[mid]) {
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
            }
            else {
                if (target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }

        return -1;
    }
};