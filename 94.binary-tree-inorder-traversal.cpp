/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (58.51%)
 * Likes:    1969
 * Dislikes: 87
 * Total Accepted:    533.3K
 * Total Submissions: 910K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
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

// #include <vector>
// #include <stdio.h>
// #include <iostream>
// #include <stack>
// using namespace std;

// struct TreeNode {
//       int val;
//       TreeNode *left;
//       TreeNode *right;
//       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        stack<TreeNode *> st;
        TreeNode *currentNode;
        vector<int> vec;

        currentNode = root;

        while (!st.empty() || currentNode != NULL) { // 栈都空了 且 当前节点是 NULL

            if (currentNode == NULL) { // 如果当前节点为 NULL

                currentNode = st.top(); // 让当前节点等于栈顶的节点 （有可能是 左、中、右
                st.pop(); // 出栈

                vec.push_back(currentNode->val); // 输出

                currentNode = currentNode->right; // 让当前节点等于右边的子节点 （可 NULL 和不 NULL 

                // 注意，这里的情况可能是 右边的子节点是 NULL，

            } else { // 当前节点不为 NULL

                st.push(currentNode); // 将当前节点先压入栈

                currentNode = currentNode->left; // 再去找左节点 （直到为 NULL
            }

        }

        return vec;
    }
};

