/*
* @Author: icher
* @Date:   2019-04-14 18:42:22
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:42:58
*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
        int left  = 0;
        int target = 0;
        int right = 0;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            target = nums[i];
            
            left = i+1;
            right = nums.size() - 1;
            while (left < right && nums[right] >= 0) {
                if (target + nums[left] + nums[right] == 0) {
                    result.push_back(vector<int>{target, nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (right > left && nums[right] == nums[right - 1]) --right;
                    ++left;
                    --right;
                }
                else if (target + nums[left] + nums[right] < 0) {
                    ++left;
                }
                else {
                    --right;
                }
            }
        }

        return result;
    }
};
