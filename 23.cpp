/*
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mapNode;
        multimap<int, ListNode*>::iterator iter;
        ListNode *head = NULL;
        ListNode *tail = NULL;
        for (int i = 0; i < lists.size(); i++) {
            head = lists[i];
            while (head) {
                mapNode.insert(pair<int, ListNode*>(head->val, head));
                head = head->next;
            }
        }

        iter = mapNode.begin();
        if (iter != mapNode.end()) {
            head = iter->second;
            tail = iter->second;
            while (++iter != mapNode.end()) {
                tail->next = iter->second;
                tail = tail->next;
            }
        }
        return head;
    }
};