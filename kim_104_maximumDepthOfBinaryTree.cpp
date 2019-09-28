/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 *
 * https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (62.10%)
 * Likes:    1579
 * Dislikes: 59
 * Total Accepted:    589.2K
 * Total Submissions: 947.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, find its maximum depth.
 * 
 * The maximum depth is the number of nodes along the longest path from the
 * root node down to the farthest leaf node.
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
 * return its depth = 3.
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
    int maxDepth(TreeNode* root) {
        
        int depth = 0;
        queue<TreeNode *> q;
        if (root != NULL) {
            q.push(root);
        }
        
        while (!q.empty())
        {
            depth++;
            int qSize = q.size();

            for (int i=0; i<qSize; i++) {

                TreeNode *top = q.front();
                q.pop();

                if (top->left != NULL) {
                    q.push(top->left);
                }

                if (top->right != NULL) {
                    q.push(top->right);
                }
            }
        }

        return depth;
        
    }
};

