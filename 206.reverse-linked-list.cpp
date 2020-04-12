/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (57.31%)
 * Likes:    3837
 * Dislikes: 82
 * Total Accepted:    885.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Reverse a singly linked list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * 
 * 
 * Follow up:
 * 
 * A linked list can be reversed either iteratively or recursively. Could you
 * implement both?
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
    start. 
        head 1 2 3 4 5
        next null

    1. 
        head 2 3 4 5
        next 1

    2.
        head 3 4 5
        next 2 1

    3.
        head 4 5
        next 3 2 1

    .......

    tmp = head->next
    head->next = new // 也是暂时的
    new = head
    head = tmp // head 复原
*/
// @lc code=start
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

       ListNode *newHead = NULL;

       while (head) {
           ListNode *tmp = head->next; // 1. 先储存 head 的后一个节点
           head->next = newHead; // 2. 把翻转的链表当前的节点赋值给 head 的后一个
           newHead = head; // 3. 将原先 head 的后一个节点赋值到 newHead
           head = tmp; // 4. head 指向它的后一个节点   
       }

       return newHead;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    ListNode n0 = ListNode(1);
    ListNode n1 = ListNode(2);
    ListNode n2 = ListNode(3);

    n0.next = &n1;
    n1.next = &n2;

    Solution *sol = new Solution();
    ListNode *res = sol->reverseList(&n0);
    return 0;
}

