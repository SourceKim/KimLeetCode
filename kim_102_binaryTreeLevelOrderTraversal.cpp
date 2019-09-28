/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.16%)
 * Likes:    1800
 * Dislikes: 47
 * Total Accepted:    437.5K
 * Total Submissions: 870.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        queue<TreeNode *> q;

        vector<vector<int>> v;

        if (root != NULL) {
            q.push(root); // 根节点入队列
        }
        
        while (!q.empty())
        {
            vector<int> vec;
            int qSize = q.size(); // 队列元素个数

            for (int i=0; i<qSize; i++) {

                TreeNode *node = q.front(); // 取出队首元素
                q.pop(); // 队首元素出队

                vec.push_back(node->val); // 记录

                // 左节点 入队
                if (node->left != NULL) {
                    q.push(node->left);
                }
                // 右节点 入队
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            v.push_back(vec); // 将该层内容加入容器
        }
    
        return v;
    }
};

