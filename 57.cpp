/*
给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。
 */

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int top = 0;
        vector<Interval> result;
        Interval temp;

        result.push_back(newInterval);
        for (int i = 0; i < intervals.size(); i++) {
           if (result[top].start < intervals[i].start) {
               if (result[top].end >= intervals[i].end) {
                   continue;
               }
               else if (result[top].end < intervals[i].start) {
                   for (vector<Interval>::iterator iter = intervals.begin()+i; iter != intervals.end(); ++iter) {
                       result.push_back(*iter);
                   }
                   break;
               }
               else {
                   result[top].end = intervals[i].end;
               }
           }
           else {
               if (result[top].start > intervals[i].end) {
                   temp = result[top];
                   result[top] = intervals[i];
                   result.push_back(temp);
                   ++top;
               }
               else if (result[top].end <= intervals[i].end) {
                   result.erase(result.begin()+top);
                   for (vector<Interval>::iterator iter = intervals.begin()+i; iter != intervals.end(); ++iter) {
                       result.push_back(*iter);
                   }
                   break;
               }
               else {
                       result[top].start = intervals[i].start;
               }
           }
        }
        return result;
    }
};