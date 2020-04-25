/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
 *
 * https://leetcode.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (50.77%)
 * Likes:    1320
 * Dislikes: 43
 * Total Accepted:    420.3K
 * Total Submissions: 827.6K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * Given two binary trees, write a function to check if they are the same or
 * not.
 * 
 * Two binary trees are considered the same if they are structurally identical
 * and the nodes have the same value.
 * 
 * Example 1:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:     1         1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:     1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * Output: false
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// @lc code=start
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        stack<TreeNode *> pSt;
        stack<TreeNode *> qSt;

        if (p != NULL) {
            pSt.push(p);
        }

        if (q != NULL) {
            qSt.push(q);
        }

        while (!pSt.empty() && !qSt.empty())
        {
            // 1. 访问栈顶
            TreeNode *topP = pSt.top();
            pSt.pop();
            TreeNode *topQ = qSt.top();
            qSt.pop();

            // 2. 对比值
            if (topP->val != topQ->val) {
                return false;
            }

            // 3. 压左边
            if (topP->left != NULL) {
                pSt.push(topP->left);
            }
            if (topQ->left != NULL) {
                qSt.push(topQ->left);
            }

            // 4. 判断左边
            if (pSt.size() != qSt.size()) {
                return false;
            }

            // 5. 压右边
            if (topP->right != NULL) {
                pSt.push(topP->right);
            }
            if (topQ->right != NULL) {
                qSt.push(topQ->right);
            }

            // 6. 判断右边
            if (pSt.size() != qSt.size()) {
                return false;
            }
            
        }

        return pSt.empty() && qSt.empty(); // 此处不可能存在两个都非空，因此仅当 pq 栈都空才是真
        
        
    }
};
// @lc code=end

