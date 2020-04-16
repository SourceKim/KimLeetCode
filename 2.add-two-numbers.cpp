/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    5977
 * Dislikes: 1559
 * Total Accepted:    1M
 * Total Submissions: 3.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // 1. 要返回的链表 & dummy
        ListNode *list = new ListNode(-1);
        ListNode *dummy = list;

        int carry = 0;
        int val1, val2, sum;
        while (l1 || l2) // l1 & l2 都遍历完
        {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;

            sum = val1 + val2 + carry;
            
            ListNode *tmp = new ListNode(sum % 10);
            list->next = tmp;

            carry = sum / 10;

            list = list->next;

            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
            
        }

        if (carry == 1) {
            list->next = new ListNode(1);
        }

        return dummy->next;
        

    }
};
// @lc code=end

