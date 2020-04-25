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
    头插法：

        有 new 指向 NULL （最后返回）
        有 head 指向第一个 （原链表）
        有 tmp 指向 head 的下一个 （每次都会更新）

        目的：
            将 new 变成： head -> new
            然后 head 要变成原 head 的下一个 （因此要有 tmp 先存着原 head 的下一个）

        终止条件：
            head = NULL

        比如： 1 - 2 - 3 - 4 - 5

            第一次：

                new = NULL 
                head = 1 - 2 - 3 - 4 - 5 - NULL

                1. 让 tmp = 2 - 3 - 4 - 5 - NULL
                2. 让 head 指向 new，变成 1 -> NULL
                3. new 也变成 1 -> NULL
                4. 让 head 变成 tmp, 即 head = 2 - 3 - 4 - 5 - NULL

            第二次：

                new = 1 -> NULL 
                head = 2 - 3 - 4 - 5 - NULL

                1. tmp = 3 - 4 - 5
                2. head 指向 new： head = 2 - 1 - NULL
                3. new 变成 head： new = 2 - 1 - NULL
                4. head = tmp： head = 3 - 4 - 5 - NULL

            第三次：

                new = 2 - 1 - NULL
                head = 3 - 4 - 5 - NULL

                1. tmp = head->next (tmp = 4 - 5 - NULL)
                2. head->next = new (head 3 - 2 - 1 - NULL)
                3. new = head (new 3 - 2 - 1 - NULL)
                4. head = tmp (head = 4 - 5 - NULL)

            第四次：

                new = 3 - 2 - 1 - NULL
                head = 4 - 5 - NULL

                1. tmp = head->next (tmp = 5 - NULL)
                2. head->next = new (head = 4 - 3 - 2 - 1 - NULL)
                3. new = head (new = 4 - 3 - 2 - 2 - 1 - NULL)
                4. head = tmp (head = 5 - NULL)

            第五次：

                new = 4 - 3 - 2 - 2 - 1 - NULL
                head = 5 - NULL

                1. tmp = head->next (tmp = NULL)
                2. head->next = new (head = 5 - 4 - 3 - 2 - 1 - NULL)
                3. new = head (new = 5 - 4 - 3 - 2 - 1 - NULL)
                4. head = NULL

            终止：

                得：new = 5 - 4 - 3 - 2 - 1 - NULL
            
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

