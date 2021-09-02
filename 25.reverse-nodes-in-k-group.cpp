/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (47.74%)
 * Likes:    4667
 * Dislikes: 432
 * Total Accepted:    399.2K
 * Total Submissions: 836.2K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes, in the end, should remain as it is.
 * 
 * You may not alter the values in the list's nodes, only nodes themselves may
 * be changed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,2,3,4,5], k = 1
 * Output: [1,2,3,4,5]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: head = [1], k = 1
 * Output: [1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is in the range sz.
 * 1 <= sz <= 5000
 * 0 <= Node.val <= 1000
 * 1 <= k <= sz
 * 
 * 
 * 
 * Follow-up: Can you solve the problem in O(1) extra memory space?
 */

#include "helper/helper.hpp"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1) return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = head;

        int i = 1; // 当前访问第几个节点
        while (cur)
        {

            // 到了第 k 个，需要把前面的翻转一下
            // 注意翻转的 range： [pre->next, cur]
            if (i % k == 0) { 
                pre = doReverse(pre, cur->next); // end 的前一个
                cur = pre->next; // 处理 end
            } else { // 否则继续前进
                cur = cur->next;
            }

            i++;
        }

        return dummy->next;
    }

private:
    // pre 是要翻转的前一个，end 是要翻转的后一个，range： (pre, end)
    ListNode *doReverse(ListNode *pre, ListNode *end) {

        ListNode *last = pre->next; // 当前处理的上一个
        ListNode *cur = last->next; // 当前处理的

        while (cur != end) // 下一个是 end 就终止了
        {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = last->next;
        }

        return last; // 返回 end 的前一个节点        
    }
};
// @lc code=end

