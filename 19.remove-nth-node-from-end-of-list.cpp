/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (34.61%)
 * Likes:    2178
 * Dislikes: 161
 * Total Accepted:    457K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 * 
 * Example:
 * 
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 * 
 * 
 * Note:
 * 
 * Given n will always be valid.
 * 
 * Follow up:
 * 
 * Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // 双指针 p1 先动，等他们距离为 n p0 再动
        ListNode *p0 = head; // 第一根指向头
        ListNode *p1 = head; // 第二根指针，将被指向 p0 + n 处

        ListNode *p0_pre; // 指向 p0 的上一个

        int dis = 0; // 两个指针的距离

        while (p1 != NULL) // 直到 p1 为 NULL
        {
            if (dis >= n) {
                // 当距离 大于 n 的时候，p0 才动
                p0_pre = p0;
                p0 = p0->next;
            } else {
                dis++;
            }
            // p1 一直在动（直到 为 NULL
            p1 = p1->next;
        }

        // 此时 p1 为 NULL，p0 在 p1 前面 n 个的地方

        // cout << p0->next->val << endl;
        // 要移除头
        if (p0 == head) {
            return p0->next;
        }

        p0_pre->next = p0->next;
        
        return head;
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode head = ListNode(1);
    // ListNode node0 = ListNode(2);
    // ListNode node1 = ListNode(3);
    // ListNode node2 = ListNode(4);
    // ListNode node3 = ListNode(5);
    // head.next = &node0;
    // node0.next = &node1;
    // node1.next = &node2;
    // node2.next = &node3;

    Solution *sol = new Solution();
    ListNode *n = sol->removeNthFromEnd(&head, 1);

    while (n) {
        cout << n->val << endl;
        n = n->next;
    }
    
    return 0;
}
