/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 *
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (36.25%)
 * Likes:    1935
 * Dislikes: 126
 * Total Accepted:    250.9K
 * Total Submissions: 666.2K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * Reverse a linked list from position m to n. Do it in one-pass.
 * 
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * 
 * Example:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
 * 
 * 
 */
#include <string.h>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        /*
        pre - 翻转的前一个节点
        start - 翻转开始的节点
        next - 开始的下一个节点
        */
        ListNode *pre, *start, *next;
        pre = dummy;

        // 1. 找到 pre start next
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
            start = pre->next;
            next = start->next;
        }

            pre->print("pre");
            start->print("start");
            next->print("next");

        // 2. 
        for (int i = 0; i < n - m; i++) {
            
            start->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = start->next;
            
            // pre->print("pre");
            // start->print("start");
            // next->print("next");
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
    ListNode n3 = ListNode(4);
    ListNode n4 = ListNode(5);

    n0.next = &n1;
    n1.next = &n2;
    // n2.next = &n3;
    // n3.next = &n4;



    Solution *sol = new Solution();
    ListNode *res = sol->reverseBetween(&n0, 1, 2);
    return 0;
}