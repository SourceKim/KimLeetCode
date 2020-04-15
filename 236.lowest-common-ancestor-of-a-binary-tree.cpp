/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (40.11%)
 * Likes:    3131
 * Dislikes: 164
 * Total Accepted:    414.9K
 * Total Submissions: 956.9K
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of itself).”
 * 
 * Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * All of the nodes' values will be unique.
 * p and q are different and both values will exist in the binary tree.
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

/* 
假设某个节点 node 是 最小公共节点，
则必定满足两个条件之下的一个
条件 A：(p & q 必定位于 node 的左子树和右子树中) 
条件 B：(他本身)
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 找到了一个目标节点 或者 root 为空，则直接返回
        // 什么时候 root 为空？就是 条件 B 递归没有 p 或者 q 的情况
        if (root == p || root == q || !root) return root;

        // 如果没找到，则从 左右 子树去找
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 如果满足 条件 A：(p & q 位于 node 的左子树和右子树中) 
        if (left && right) return root;

        // 否则：就是 p q 不是位于两侧的情况，单边为 NULL （题目限定不可能都为 NULL）
        return left ? left : right;
    }
};
// @lc code=end

