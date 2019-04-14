/*
* @Author: icher
* @Date:   2019-04-14 18:48:48
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:49:20
*
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

示例:

给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* front = head;
        ListNode* behind = head;
        ListNode* tmp    = NULL;
        if (head == NULL || head->next == NULL) {
            return head;
        }

        tmp = front->next;
        front->next = tmp->next;
        tmp->next = front;
        head = tmp;
        
        behind = front->next;
        while (behind && behind->next) {
            tmp = behind->next;
            behind->next = tmp->next;
            tmp->next = behind;
            front->next = tmp;
            front = behind;
            behind = behind->next;
        }

        return head;
    }
};
