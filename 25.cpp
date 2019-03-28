/*
给出一个链表，每 k 个节点一组进行翻转，并返回翻转后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么将最后剩余节点保持原有顺序。

示例 :

给定这个链表：1->2->3->4->5

当 k = 2 时，应当返回: 2->1->4->3->5

当 k = 3 时，应当返回: 3->2->1->4->5

说明 :

你的算法只能使用常数的额外空间。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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

     ListNode* reverseGroup(ListNode* head) {
        ListNode* phead = NULL;
        ListNode* tmp = NULL;
        while (head) {
            tmp = head;
            head = head->next;
            tmp->next = phead;
            phead = tmp;
        }
        return phead;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* rhead = head;
        ListNode* rtail = NULL;
        ListNode* tmphead = head;
        ListNode* tail    = head;
        int count = k;
        bool flag = true;

        while (tmphead) {
            while (--count && (tmphead = tmphead->next));
            if (tmphead != NULL && count == 0) {
                rtail = tmphead;
                tmphead = tmphead->next;
                rtail->next = NULL;
                rtail = rhead;
                rhead = reverseGroup(rhead);
                if (flag) {
                    flag = false;
                    head = rhead;
                }
                else {
                    tail->next = rhead;
                }
                tail = rtail;
                rtail->next = tmphead;
                rhead = tmphead;
                count = k;
            }
        }
        return head;
    }
};