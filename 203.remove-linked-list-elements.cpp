/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (36.50%)
 * Likes:    974
 * Dislikes: 59
 * Total Accepted:    252.7K
 * Total Submissions: 692.4K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example:
 * 
 * 
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 * 
 * 
 */
#include<stdio.h>
#include<iostream>
 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 using namespace std;
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
    ListNode* removeElements(ListNode* head, int val) {

        if (head == NULL) {
            return NULL;
        }
        
        ListNode *cur = head;
        ListNode *last = NULL;

        while (cur != NULL)
        {
            if (cur->val == val) {
                if (last != NULL) {
                    last->next = cur->next;
                } else {
                    head = cur->next;
                }
            } else {
                last = cur;
            }
            cur = cur->next;


        }

        return head;
        
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    ListNode head = ListNode(1);
    ListNode node = ListNode(2);
    head.next = &node;
    Solution *sol = new Solution();
    ListNode *n = sol->removeElements(&head, 1);
    cout << n->val << endl;
    return 0;
}
