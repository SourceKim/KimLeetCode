/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (32.65%)
 * Likes:    1525
 * Dislikes: 100
 * Total Accepted:    208.7K
 * Total Submissions: 595.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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

    void print(string name) {
        cout << name << ": ";
        ListNode *ptr = this;
        while (ptr)
        {
            cout << " " << ptr->val;
            ptr = ptr->next;
        }
        cout << endl;
    }
};

/* 
    1. 通过 slow-fast 找到中点
    2. 断开链表 l1 l2
    3. 翻转 l2
    4. 间隔插入 l2 到 l1
 */

// @lc code=start

class Solution {
public:
    void reorderList(ListNode* head) {

        if (!head) return;

        // 1
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2
        fast = slow->next;
        slow->next = NULL;

        // fast->print("fast");
        // head->print("head");
        // 3
        ListNode *last = NULL;
        while (fast)
        {
            ListNode *tmp = fast->next;
            fast->next = last;
            last = fast;
            fast = tmp;
        }

        // last->print("fast");
        
        // 4
        while (head && last)
        {
            ListNode *tmp = head->next;
            head->next = last;
            last = last->next;
            head->next->next = tmp;
            head = tmp;
        }

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode n0 = ListNode(1);
    ListNode n1 = ListNode(2);
    ListNode n2 = ListNode(3);
    ListNode n3 = ListNode(4);
    ListNode n4 = ListNode(5);

    n0.next = &n1;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    Solution *sol = new Solution();
    sol->reorderList(&n0);
    n0.print("res");
    return 0;
}
