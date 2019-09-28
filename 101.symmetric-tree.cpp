/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 *
 * https://leetcode.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (44.41%)
 * Likes:    2665
 * Dislikes: 59
 * Total Accepted:    466.9K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric
 * around its center).
 * 
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 
 * 
 * But the following [1,2,2,null,3,null,3] is not:
 * 
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 
 * 
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 * 
 */
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
    bool isSymmetric(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        queue<TreeNode *> q0, q1;
        q0.push(root->left);
        q1.push(root->right);
        
        while (!q0.empty() && !q1.empty())
        {
            TreeNode *node0 = q0.front();
            TreeNode *node1 = q1.front();
            q0.pop();
            q1.pop();

            if (node0 == NULL && node1 == NULL) {
                // 两个都为空，有可能右边还有
                continue;
            }

            if ((node0 == NULL && node1 != NULL) || (node0 != NULL && node1 == NULL)) {
                // 一 NULL 一非 NULL
                return false;
            }

            if (node0->val != node1->val) {
                return false;
            }

            q0.push(node0->left);
            q0.push(node0->right);

            q1.push(node1->right);
            q1.push(node1->left);
        }
        return true;
    }
};

// int main(int argc, char const *argv[])
// {
//     TreeNode r = TreeNode(1);

//     TreeNode l0 = TreeNode(2);
//     TreeNode r0 = TreeNode(2);
//     r.left = &l0;
//     r.right = &r0;

//     TreeNode r0_0= TreeNode(3);
//     TreeNode r0_1 = TreeNode(3);
//     l0.right = &r0_0;
//     r0.right = &r0_1;

//     Solution *sol = new Solution();
//     bool res = sol->isSymmetric(&r);

//     cout << res << endl;
    
//     return 0;
// }

