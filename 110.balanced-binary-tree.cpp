/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 *
 * https://leetcode.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (41.73%)
 * Likes:    1457
 * Dislikes: 132
 * Total Accepted:    358K
 * Total Submissions: 857K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, determine if it is height-balanced.
 * 
 * For this problem, a height-balanced binary tree is defined as:
 * 
 * 
 * a binary tree in which the depth of the two subtrees of every node never
 * differ by more than 1.
 * 
 * 
 * Example 1:
 * 
 * Given the following tree [3,9,20,null,null,15,7]:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * Return true.
 * 
 * Example 2:
 * 
 * Given the following tree [1,2,2,3,3,null,null,4,4]:
 * 
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * Return false.
 * 
 */

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
// #include <stdio.h>
// #include <iostream>
// #include <queue>

// using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    bool isBalanced(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        if (abs(depth(root->left) - depth(root->right)) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int depth(TreeNode *node) {
        if (node == NULL) {
            return 0;
        }
        int leftD = depth(node->left);
        int rightD = depth(node->right);
        return max(leftD, rightD) + 1;
    }
};

// int main(int argc, char const *argv[])
// {
//     TreeNode r = TreeNode(3);

//     // TreeNode l0 = TreeNode(9);
//     // TreeNode r0 = TreeNode(20);
//     // r.left = &l0;
//     // r.right = &r0;

//     // TreeNode r0_0= TreeNode(15);
//     // TreeNode r0_1 = TreeNode(7);
//     // r0.left = &r0_0;
//     // r0.right = &r0_1;

//     Solution *sol = new Solution();
//     bool res = sol->isBalanced(&r);

//     cout << res << endl;
    
//     return 0;
// }
// @lc code=end

