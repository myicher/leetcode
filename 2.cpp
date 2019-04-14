/*
* @Author: icher
* @Date:   2019-04-14 18:27:34
* @Last Modified by:   icher
* @Last Modified time: 2019-04-14 18:28:47
*
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = NULL;
        ListNode *cursor = NULL;
        int further = 0;

        while (l1 != NULL || l2 != NULL) {
            ListNode *tmp =new ListNode(0);

            if (l1 != NULL) {
                tmp->val = l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                tmp->val += l2->val;
                l2 = l2->next;
            }
            tmp->val += further;
            further = tmp->val / 10;
            tmp->val = tmp->val % 10;

            if (cursor == NULL) {
                result = tmp;
                cursor = tmp;
            }
            else {
                cursor->next = tmp;
                cursor = tmp;
            }
        }
        
        if (further) {
            ListNode *tmp = new ListNode(0);
            tmp->val  = further;
            cursor->next = tmp;
            cursor = tmp;
        }

        return result;
    }
};
