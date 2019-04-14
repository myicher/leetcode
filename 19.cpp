/*
* @Author: icher
* @Date:   2019-04-14 18:46:20
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:46:45
*
给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

示例：

给定一个链表: 1->2->3->4->5, 和 n = 2.

当删除了倒数第二个节点后，链表变为 1->2->3->5.
说明：

给定的 n 保证是有效的。
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *pre = head;
        ListNode *next = head;
        int count = 0;

        while (next && count < n) {
            next = next->next;
            ++count;
        }

        if (count == n) {
            if (next == NULL) {
                next = head;
                head = head->next;
                delete next;
            }
            else{
                while (next->next != NULL) {
                    pre = pre->next;
                    next = next->next;
                }
                next = pre->next;
                pre->next = next->next;
                delete next;
            }
        }
        return head;
    }
};
