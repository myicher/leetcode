/*
* @Author: icher
* @Date:   2019-04-14 18:45:32
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:52:52
*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。

注意：

答案中不可以包含重复的四元组。

示例：

给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。

满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
             vector<vector<int>> result;
        int compareNum  = 0;
        int left = 0;
        int right = 0;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < (int)nums.size() - 1; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            for (int j = i+1; j < nums.size(); ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) {
                    continue;
                };
                compareNum = target - nums[i] - nums[j];

                left = j+1;
                right = nums.size() - 1;
                while (left < right) {
                   
                    if (compareNum - nums[left] - nums[right] == 0) {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left + 1 < right && nums[left] == nums[left + 1]) ++left;
                        while (right - 1 > left && nums[right] == nums[right - 1]) --right;
                        ++left;
                        --right;
                    }
                    else if (compareNum - nums[left] - nums[right] > 0) {
                        ++left;
                    }
                    else {
                        --right;
                    }
                }
            }
        }
       
        return result;
    }
};
