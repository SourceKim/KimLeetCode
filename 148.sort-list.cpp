/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (37.64%)
 * Likes:    2292
 * Dislikes: 115
 * Total Accepted:    242.4K
 * Total Submissions: 603.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
// 归并排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        
        if (!head) return NULL;
        if (!head->next) return head;

        // 1. 先用快慢指针找到中点
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next; // 2. 第二段链表的起点
        slow->next = NULL; // 3. 断开链表，这样就有以 head & fast 为开头的两段链表了

        // 4. 递归自己，对 两段分别排序
        ListNode *l1 = sortList(fast);
        ListNode *l2 = sortList(head);
        
        // 5. 排序之后合并
        return mergeTwoLists(l1, l2);
    }

    // [21] Merge Two Sorted Lists 合并两个有序链表
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }

        ListNode *n = new ListNode(-1);
        ListNode *ptr = n;

       while (l1 != NULL && l2 != NULL)
       {
           // 选一个小的值的料表，做步增 & 连接到新的链表上面
           if (l1->val < l2->val) { 
                n->next = l1;
                l1 = l1->next;
                n = n->next;
           } else {
                n->next = l2;
                l2 = l2->next;
                n = n->next;
           }
       }
       
       // 假设有一方排序完了 （即另一方没有排序完毕，直接接到后面即可
       if (l1 != NULL) {
           n->next = l1;
       }

       if (l2 != NULL) {
           n->next = l2;
       }

       return ptr->next;
        
    }
};
// @lc code=end

