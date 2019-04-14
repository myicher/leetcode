/*
* @Author: icher
* @Date:   2019-04-14 18:51:56
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:52:20
*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         int size = nums.size();
        int pos = -1;

        if (size == 0 || size == 1) {
            return;
        }

        for (int i = size - 2; i >= 0; --i) {
            for (int j = size - 1; j > i; --j) {
                if (nums[j] > nums[i] && pos == -1) {
                    if (pos == -1) {
                        pos = j;
                    } 
                    else {
                        if (nums[j] < nums[pos]) {
                            pos = j;
                        }
                    }
                }
            }
            if (pos != -1) {
                nums[i] += nums[pos];
                nums[pos] = nums[i] - nums[pos];
                nums[i]   = nums[i] - nums[pos];
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }

        for (int i = 0; i < size/2; ++i) {
            nums[i] += nums[size - i -1];
            nums[size - i - 1]  = nums[i] - nums[size - i - 1];
            nums[i] = nums[i] - nums[size - i - 1];
        }
    }
};
