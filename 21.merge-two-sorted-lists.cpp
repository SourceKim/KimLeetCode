/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (49.26%)
 * Likes:    2727
 * Dislikes: 400
 * Total Accepted:    705.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 * 
 * Example:
 * 
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 * 
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
int main(int argc, char const *argv[])
{
    ListNode a0 = ListNode(1);
    ListNode a1 = ListNode(3);
    ListNode a2 = ListNode(4);

    ListNode b0 = ListNode(1);
    ListNode b1 = ListNode(2);
    ListNode b2 = ListNode(4);

    a0.next = &a1;
    a1.next = &a2;

    b0.next = &b1;
    b1.next = &b2;

    Solution *sol = new Solution();
    ListNode *n = sol->mergeTwoLists(&a0, &b0);

    while (n) {
        cout << n->val << endl;
        n = n->next;
    }

    return 0;
}


