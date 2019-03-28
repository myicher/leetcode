/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1  = 0;
        int size2  = 0;
        int count  = 0;
        int index1 = 0;
        int index2 = 0;
        double  middle = 0;
        size1 = nums1.size();
        size2 = nums2.size();
        if (size1 == 0 || size2 == 0) {
            return -1;
        }
        else {
            middle = nums1[0];
        }

        while (count < (size1 + size2 + 1) / 2) {
            if (index1 < size1 && index2 < size2) {
                if (nums1[index1] < nums2[index2]) {
                    middle = nums1[index1];
                    index1++;
                }
                else {
                    middle = nums2[index2];
                    index2++;
                }
            }
            else if (index1 >= size1) {
                middle = nums2[index2];
                index2++;
            }
            else {
                middle = nums1[index1];
                index1++;
            }

            count++;
        }
        if (((size1 + size2) & 0x01) == 0) {
            if (index1 >= size1 || index2 < size2 && nums1[index1] > nums2[index2] ) {
                middle = (middle + nums2[index2]) / 2;
            }
            else {
                middle = (middle + nums1[index1]) / 2;
            }
        }
        printf("%d %d %f\n", index1, index2, middle);
        return middle;
    }
};