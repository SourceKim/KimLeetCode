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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (!head->next) return NULL;
        
        // 双指针 p1 先动，等他们距离为 n p0 再动
        ListNode *p0 = head; // 第一根指向头
        ListNode *p1 = head; // 第二根指针，将被指向 p0 + n 处

        // 不合并到下面，是怕要删除头结点
        while (n > 0) {
            p1 = p1->next;
            n--;
        }

        if (!p1) return head->next; // 删除头结点

        while (p1->next) {  // 当 P1 移动到了最后，就停止
            p0 = p0->next;
            p1 = p1->next;
        }
        
        p0->next = p0->next->next;
        
        return head;
        
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode head = ListNode(1);
    ListNode node0 = ListNode(2);
    // ListNode node1 = ListNode(3);
    // ListNode node2 = ListNode(4);
    // ListNode node3 = ListNode(5);
    head.next = &node0;
    // node0.next = &node1;
    // node1.next = &node2;
    // node2.next = &node3;

    Solution *sol = new Solution();
    ListNode *n = sol->removeNthFromEnd(&head, 2);

    while (n) {
        cout << n->val << endl;
        n = n->next;
    }
    
    return 0;
}
