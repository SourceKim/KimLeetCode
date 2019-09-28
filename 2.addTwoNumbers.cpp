/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (31.81%)
 * Likes:    5975
 * Dislikes: 1557
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// #include <stdio.h>
// #include <iostream>

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode *p1, *p2;

        p1 = l1;
        p2 = l2;
        
        bool use1 = true; // 是否使用链表 1
        bool needCarry = false; // 是否需要进位
        while(p1!=NULL || p2!=NULL)
        {
            bool lastNeedCarry = needCarry; // 上一次的结果是否需要进位

            needCarry = false;
            int sum = 0;
            if (p1!=NULL) {
                sum += p1->val;
            } else {
                use1 = false;
            }
            if (p2!=NULL) {
                sum += p2->val;
            }

            if (lastNeedCarry) {
                sum++;
            }

            if (sum / 10 > 0) {
                needCarry = true;
                sum %= 10;
            }

            if (p1!=NULL) {
                p1->val = sum;
                p1 = p1->next;
            }
            if (p2!=NULL) {
                p2->val = sum;
                p2 = p2->next;
            }

        }
        if (use1) {
            if (needCarry) {
                ListNode *lastNode = l1;
                while (lastNode->next!=NULL)
                {
                    lastNode = lastNode->next;
                }
                
                ListNode *carryNode = new ListNode(1);
                lastNode->next = carryNode;
            }
            return l1;
        } else {
            if (needCarry) {
                ListNode *lastNode = l2;
                while (lastNode->next!=NULL)
                {
                    lastNode = lastNode->next;
                }
                ListNode *carryNode = new ListNode(1);
                lastNode->next = carryNode;
            }
            return l2;
        }
        
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution *sol = new Solution();
//     ListNode *n1 = new ListNode(9);
//     ListNode *n2 = new ListNode(9);
//     n1->next = n2;
//     ListNode *n3 = new ListNode(1);
//     ListNode *res = sol->addTwoNumbers(n1, n3);

//     ListNode *p = res;
//     while (p!=NULL)
//     {
//         std::cout << p->val << std::endl;
//         p = p->next;
//     }
//     std::cout << "end" << std::endl;
    
//     return 0;
// }


