/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (46.61%)
 * Likes:    1434
 * Dislikes: 126
 * Total Accepted:    362.8K
 * Total Submissions: 778.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
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
    ListNode* swapPairs(ListNode* head) {

        /*
        1. 生成一个空 Node，接到链表头
        2. 声明 3 个指针： p0 / p1 / p2， p0 指向上一步的空 Node， p1 指向第一个，p2 指向第二个
        3. p1 & p2 交换 (p0 指向 交换后 的 p2，p2 指向 p1，p1 指向 p2->next)
        4. p0 & p1 & p2 一起 +2
        5. 重复 3、4，直到 p1 的 next 是 NULL
        */

       if (head == NULL || head->next == NULL) {
           return head;
       }

       // 1.
       ListNode *fakeHead = new ListNode(100);
       fakeHead->next = head;

       // 2.
       ListNode *p0 = fakeHead;
       ListNode *p1 = fakeHead->next;
       ListNode *p2 = fakeHead->next->next;

       // 3.
       bool p2NextIsNull = false;
       while (p2)
       {
        //    cout << "==" << p0->val << p1->val << p2->val << "==" << endl;
           ListNode *tmpP2Next = p2->next;

           p2->next = p1;
           p1->next = tmpP2Next;
           p0->next = p2;

//    cout << "++" << p0->next->val << p1->next->val << p2->next->val << "++" << endl;
            if (tmpP2Next == NULL) {
                return fakeHead->next;
            }
           p0 = p2->next;
           p1 = p0->next;
           p2 = p1->next;
        //    cout << "++" << p0->val << p1->val << p2->val << "++" << endl;
        //    i++;
       }
       
       return fakeHead->next;
        
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
    ListNode *res = sol->swapPairs(&n0);
    while (res != NULL)
    {
        cout << res->val << endl;
        res = res->next;
    }
    
    return 0;
}


