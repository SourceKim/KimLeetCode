/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (50.67%)
 * Likes:    1382
 * Dislikes: 275
 * Total Accepted:    214.1K
 * Total Submissions: 405.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * Note:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
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

// @lc code=start
/* 
    奇偶链表 （要实现的是将链表的 0 - 1 - 2 - 3 - 4 - 5 变成 0 1 3 2 4）

    注意这里的数字指的是下标，而不是 node 的值

    将奇数的排到前面，偶数的排到后面即可
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head) return NULL;

        ListNode *odd = head; // 奇链
        ListNode *even = head->next; // 偶链

        ListNode *evenHead = even; // 指向 even，用来在后面连接两条链

        while (odd->next && even->next)
        {
            /*  有  1 - 2 - 3 - 4 - 5

                第一步：
                    odd：  1 - 3 - 4 - 5
                    even： 2 - 3 - 4 - 5
                
                第二步：
                    odd：  3 - 4 - 5
                    even： 2 - 3 - 4 - 5
                
                第三步：
                    odd：  3 - 4 - 5
                    even： 2 - 3 - 4 - 5
                
                第四步：
                    odd：  3 - 4 - 5
                    even： 3 - 4 - 5

             */
            odd->next = even->next; // 先将 偶数 的下一个存起来
            // odd->print("odd - ");
            // even->print("even - ");
            // head->print("head - ");
            odd = odd->next; // 奇数的下一个 就是 偶数的下一个 （应用上一步存的）
            // odd->print("odd - ");
            // even->print("even - ");
            // head->print("head - ");
            even->next = odd->next; // 偶数的下一个 就是 奇数的下一个
            // odd->print("odd - ");
            // even->print("even - ");
            // head->print("head - ");
            even = even->next;
            // odd->print("odd - ");
            // even->print("even - ");
            // head->print("head - ");
        }

        odd->next = evenHead;
        // head->print("head");
        return head;
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
    sol->oddEvenList(&n0);
    return 0;
}

