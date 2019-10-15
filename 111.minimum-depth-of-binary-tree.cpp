/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 *
 * https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (35.89%)
 * Likes:    862
 * Dislikes: 473
 * Total Accepted:    327.6K
 * Total Submissions: 911.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its minimum depth.
 * 
 * The minimum depth is the number of nodes along the shortest path from the
 * root node down to the nearest leaf node.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * return its minimum depth = 2.
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {

        if (!root) return 0;
        int L = minDepth(root->left), R = minDepth(root->right);
        return 1 + (L && R ? min(L, R) : max(L, R));
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    TreeNode n0 = TreeNode(3);
    TreeNode n1 = TreeNode(9);
    TreeNode n2 = TreeNode(20);
    TreeNode n3 = TreeNode(15);
    TreeNode n4 = TreeNode(7);

    n0.left = &n1;
    n0.right = &n2;
    n2.left = &n3;
    n2.right = &n4;

    Solution *sol = new Solution();
    int res = sol->minDepth(&n0);

    cout << res << endl;

    return 0;
}

