/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 *
 * https://leetcode.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (31.20%)
 * Likes:    2849
 * Dislikes: 240
 * Total Accepted:    294.7K
 * Total Submissions: 902.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty binary tree, find the maximum path sum.
 * 
 * For this problem, a path is defined as any sequence of nodes from some
 * starting node to any node in the tree along the parent-child connections.
 * The path must contain at least one node and does not need to go through the
 * root.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * Output: 6
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * Output: 42
 * 
 * 
 */

#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution {
    /* 
        left & right 分别表示左右的最大值，这个值是要喝 root 的值相加的，
        因此如果是负数的话，直接 +0

        然后更新 全局最大值
     */
public:
    int maxPathSum(TreeNode* root) {

        int gloabalMax = INT_MIN;
        traversalOfEachNode(root, gloabalMax);
        return gloabalMax;
    }

private:
     // 全局最小值

    int traversalOfEachNode(TreeNode *root, int &tmpMax) {
        if (!root) return 0;

        int left = max(traversalOfEachNode(root->left, tmpMax), 0); // 左边最大值
        int right = max(traversalOfEachNode(root->right, tmpMax), 0); // 右边最大值

        tmpMax = max(tmpMax, left + right + root->val); // 计算全局最大值

        return root->val + max(left, right); // 返回当前节点的最大值
    }
};
// @lc code=end

