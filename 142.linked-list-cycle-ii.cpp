/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 *
 * https://leetcode.com/problems/linked-list-cycle-ii/description/
 *
 * algorithms
 * Medium (33.77%)
 * Likes:    2270
 * Dislikes: 189
 * Total Accepted:    291K
 * Total Submissions: 812.4K
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given a linked list, return the node where the cycle begins. If there is no
 * cycle, return null.
 * 
 * To represent a cycle in the given linked list, we use an integer pos which
 * represents the position (0-indexed) in the linked list where tail connects
 * to. If pos is -1, then there is no cycle in the linked list.
 * 
 * Note: Do not modify the linked list.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * second node.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2], pos = 0
 * Output: tail connects to node index 0
 * Explanation: There is a cycle in the linked list, where tail connects to the
 * first node.
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1], pos = -1
 * Output: no cycle
 * Explanation: There is no cycle in the linked list.
 * 
 * 
 * 
 * 
 * 
 * 
 * Follow-up:
 * Can you solve it without using extra space?
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

// @lc code=start
/* 
    如 141 用 slow-fast 即可

    设相遇点为 meet

    当他们相遇之后，再次另指针跑起来，但是 fast 这次只走一步 & slow 指向 head，直到再次相遇

    那么再次相遇的点 Meet2 就是环形的入口了

    数学证明： （自行画图）

        设 x1 为 head 到 环入口 的节点数
        设 x2 为 环入口 到 第一次相遇 的节点数
        设 x3 为 第一次相遇 到 环入口 的节点数

        第一次相遇的时候：（设 l1 为 slow 走过的节点数，l2 为 fast 走过的节点数）

            l1 = x1 + x2
            l2 = x1 + x2 + x3 + x2

        又因 fast 的速度是 slow 的两倍，因此相同时间内走过的节点数量也是两倍

            l1 * 2 = l2
        
        得：

            x1 = x3

    因此，只需要让 slow 从头走，fast 从第一次相遇走，再次相遇的节点就是 环入口了


 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (!head) return NULL;

        ListNode *slow = head, *fast = head;

        bool hasCycle = false;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle) return NULL;

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
// @lc code=end

