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

       if (head == NULL || head->next == NULL) {
           return head;
       }

       // 1.
       ListNode *dummy = new ListNode(-1);
       dummy->next = head;

       // 2. pre 指向要交换开始的前一个，tmp 指向要交换的
       ListNode *pre = dummy, *tmp;

       // 3.
       while (pre->next && pre->next->next)
       {
           /* 
                初始： 
                    pre 指向 dummy

                最终目的：
                    让 1 指向 3
                    让 2 指向 1

                    
            */
            tmp = pre->next; // tmp 指向 1
            pre->next = pre->next->next;    // pre 下一个指向 2
            tmp->next = tmp->next->next;    // tmp （1）指向 3
            pre->next->next = tmp;          // pre 的下一个（2）指向 1

            /* 
                至此 已经完成了 swap

                2 的 下一个(next) 是 1
                1 的 下一个(next) 是 3

            */ 

            // 让 pre 到 tmp（1）的位置，继续
            pre = tmp;
       }
       
       return dummy->next;
        
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


